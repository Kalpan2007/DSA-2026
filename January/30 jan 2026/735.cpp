class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        for (int a : asteroids) {
            if (a > 0) {
                s.push(a);
            } else {
                while (!s.empty() && s.top() > 0 && s.top() < -a) {
                    s.pop();
                }

                if (s.empty() || s.top() < 0) {
                    s.push(a);
                }

                if (!s.empty() && s.top() == -a) {
                    s.pop();
                }
            }
        }

        vector<int> res(s.size());
        int i = s.size() - 1;

        while (!s.empty()) {
            res[i--] = s.top();
            s.pop();
        }

        return res;        
    }
};