class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans = 0;
        int l = 0;
        multiset<int> st; 
        for(int i = 0 ; i < n ; i++){
            st.insert(nums[i]);
            while(l <=i && (long long)(*st.rbegin() - *st.begin()) * (i-l+1) > k){
                auto it = st.find(nums[l]);
                st.erase(it);
                l++;
            }
            ans += (i-l+1);
        }
        return ans;
    }
};