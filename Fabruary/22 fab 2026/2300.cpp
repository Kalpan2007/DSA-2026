class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long su) {
        int n = s.size();
        int m = p.size();

        vector<int> ans(n,0);
        sort(p.begin(),p.end());

        for(int i = 0;i < n;i++){
            int spell = s[i];
            int left = 0;
            int right = m-1;

            while(left <= right){
                int mid = (left + right) / 2;
                long long product = (long long)spell * (long long)p[mid];

                if(product >= su){
                    right = mid - 1;
                }else{
                    left =mid +1;
                }
            }
            ans[i] = m-left;
        }
        return ans;
    }
};