class Solution {
public:
    typedef long long ll;
    long long countSubarrays(vector<int>& nums, int k, int m) {
        int n = nums.size();
        ll ans =0;

        vector<int> freq1(100001 , 0) , freq2(100001 , 0);
        int d1 = 0;
        int d2 = 0;
        int s1 = 0;
        int r1 = 0;
        int r2 = 0;

        for(int l = 0 ; l < n ;l++){

            while(r1 < n && (d1 < k || (d1 == k && s1 < k))){
                int val = nums[r1];
                freq1[val]++;
                if(freq1[val]==1) d1++;
                if(freq1[val]==m) s1++;
                r1++;
            }

            while(r2 < n){
                int val = nums[r2];
                if (freq2[val] == 0 && d2 == k) break;

                if (++freq2[val] == 1) d2++;
                r2++;
            }

            if(d1 == k && s1 == k && r2 >= r1){
                ans += (r2 - r1 + 1);
            }


            int left = nums[l];
            if(freq1[left] ==m ) s1--;
            if(--freq1[left]==0) d1--;
            if(--freq2[left]==0) d2--;
        }
        return ans;
    }
};