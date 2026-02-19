"""
Auto Problem Counter for DSA Repository
========================================
Recursively counts solution files and updates the README.md badge.

Supported extensions: .cpp .py .java .js .ts .sql
Marker format in README:
    <!-- TOTAL_PROBLEMS_START -->N<!-- TOTAL_PROBLEMS_END -->
"""

import os
import re
import sys

# ── Configuration ─────────────────────────────────────────────────────────────
REPO_ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
README_PATH = os.path.join(REPO_ROOT, "README.md")
SOLUTION_EXTENSIONS = {".cpp", ".py", ".java", ".js", ".ts", ".sql"}

# Directories to scan (month folders at repo root)
SCAN_DIRS = []
for entry in os.listdir(REPO_ROOT):
    full = os.path.join(REPO_ROOT, entry)
    if os.path.isdir(full) and not entry.startswith("."):
        SCAN_DIRS.append(full)

MARKER_PATTERN = re.compile(
    r"(<!-- TOTAL_PROBLEMS_START -->)\d*(<!-- TOTAL_PROBLEMS_END -->)"
)


def count_solutions(directories: list[str]) -> int:
    """Recursively count files with solution extensions."""
    total = 0
    for scan_dir in directories:
        for root, _dirs, files in os.walk(scan_dir):
            for f in files:
                ext = os.path.splitext(f)[1].lower()
                if ext in SOLUTION_EXTENSIONS:
                    total += 1
    return total


def update_readme(count: int) -> bool:
    """Replace the marker in README.md with the new count. Returns True if changed."""
    # Handle potential BOM (UTF-8-SIG) or fallback encodings
    for enc in ("utf-8-sig", "utf-8", "utf-16", "latin-1"):
        try:
            with open(README_PATH, "r", encoding=enc) as fh:
                content = fh.read()
            break
        except (UnicodeDecodeError, UnicodeError):
            continue
    else:
        print("❌ Could not read README.md with any supported encoding.")
        return False

    new_content, replacements = MARKER_PATTERN.subn(
        rf"\g<1>{count}\g<2>", content
    )

    if replacements == 0:
        print("⚠️  Marker not found in README.md — skipping update.")
        return False

    if new_content == content:
        print(f"✅ Count unchanged ({count}). No write needed.")
        return False

    with open(README_PATH, "w", encoding="utf-8") as fh:
        fh.write(new_content)

    print(f"✅ README.md updated — Total problems: {count}")
    return True


def main() -> None:
    print(f"📂 Repo root: {REPO_ROOT}")
    print(f"📂 Scanning: {[os.path.basename(d) for d in SCAN_DIRS]}")

    count = count_solutions(SCAN_DIRS)
    print(f"🔢 Solutions found: {count}")

    changed = update_readme(count)
    # Exit code 0 regardless — the workflow handles "no changes" gracefully
    sys.exit(0)


if __name__ == "__main__":
    main()
