
class Solution {
    vector<int> count;
    vector<double> length;
    vector<double> X;

    void update(int node, int start, int end, int l, int r, int val) {
        if (l >= end || r <= start) return;
        if (l <= start && end <= r) {
            count[node] += val;
        } else {
            int mid = (start + end) / 2;
            update(node * 2, start, mid, l, r, val);
            update(node * 2 + 1, mid, end, l, r, val);
        }

        if (count[node] > 0) {
            length[node] = X[end] - X[start];
        } else if (end - start == 1) {
            length[node] = 0;
        } else {
            length[node] = length[node * 2] + length[node * 2 + 1];
        }
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        X.clear();
        for (auto& sq : squares) {
            X.push_back((double)sq[0]);
            X.push_back((double)sq[0] + sq[2]);
        }
        sort(X.begin(), X.end());
        X.erase(unique(X.begin(), X.end()), X.end());

        int n_coords = X.size();

        struct Event {
            double y;
            int type;
            double x1, x2;
            bool operator<(const Event& other) const {
                return y < other.y;
            }
        };

        vector<Event> events;
        for (auto& sq : squares) {
            events.push_back({(double)sq[1], 1, (double)sq[0], (double)sq[0] + sq[2]});
            events.push_back({(double)sq[1] + sq[2], -1, (double)sq[0], (double)sq[0] + sq[2]});
        }
        sort(events.begin(), events.end());

        count.assign(4 * n_coords, 0);
        length.assign(4 * n_coords, 0.0);

        struct Strip {
            double y;
            double height;
            double width;
        };

        vector<Strip> strips;
        double total_area = 0;

        for (int i = 0; i < (int)events.size(); ++i) {
            int l_idx = lower_bound(X.begin(), X.end(), events[i].x1) - X.begin();
            int r_idx = lower_bound(X.begin(), X.end(), events[i].x2) - X.begin();
            update(1, 0, n_coords - 1, l_idx, r_idx, events[i].type);

            if (i + 1 < (int)events.size()) {
                double h = events[i + 1].y - events[i].y;
                if (h > 0) {
                    double active_width = length[1];
                    total_area += active_width * h;
                    strips.push_back({events[i].y, h, active_width});
                }
            }
        }

        double target = total_area / 2.0;
        double current_area = 0;

        for (auto& strip : strips) {
            double strip_area = strip.width * strip.height;
            if (current_area + strip_area >= target) {
                double needed = target - current_area;
                return strip.y + (needed / strip.width);
            }
            current_area += strip_area;
        }

        return events.back().y;
    }
};