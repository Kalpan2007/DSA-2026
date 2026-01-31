class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int ind=0;
        int max_ = 0;
        for(int i=0;i<n;i++){
            ind += gain[i];
            max_ = max(max_, ind);
        }
        return max_;
    }
};