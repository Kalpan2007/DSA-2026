class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        vector<int> vec = nums;
        int n= vec.size();
        int ans = 0;

        for(int i = 0;i<n;i++){
            int s =0 ;
            unordered_set<int> st;
            for(int j = i ; j < n ; j++){
                s += vec[j];
                st.insert(vec[j]);
                if(st.count(s)) ans++;
            }
        }
        return ans;
    }
};