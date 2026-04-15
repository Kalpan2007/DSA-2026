class Solution {
public:
    int closestTarget(vector<string>& words, string target, int start_index) {
        int n = words.size();

    int right_steps = 0;
    while (right_steps < n) {
        int idx = (start_index + right_steps) % n;
        if (words[idx] == target) {
            break;
        }
        right_steps++;
    }

    int left_steps = 0;
    while (left_steps < n) {
        int idx = (start_index - left_steps + n) % n;
        if (words[idx] == target) {
            break;
        }
        left_steps++;
    }

    if (right_steps == n && left_steps == n) {
        return -1;
    }

    return min(right_steps, left_steps);

    }
};