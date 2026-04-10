class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    int n = positions.size();
    
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&](int a, int b) {
        return positions[a] < positions[b];
    });
    
    vector<int> stack;        
    vector<bool> dead(n, false);
    
    for (int i : indices) {
        if (directions[i] == 'R') {
            stack.push_back(i);
        } else {
            while (!stack.empty()) {
                int top = stack.back();
                
                if (healths[top] > healths[i]) {       
                    healths[top]--;
                    dead[i] = true;
                    break;
                } else if (healths[top] < healths[i]) { 
                    healths[i]--;
                    dead[top] = true;
                    stack.pop_back();
                } else {                                 
                    dead[top] = true;
                    dead[i]   = true;
                    stack.pop_back();
                    break;
                }
            }
        }
    }
    
    vector<int> result;
    for (int i = 0; i < n; i++)
        if (!dead[i])
            result.push_back(healths[i]);
    
    return result;
    }
};