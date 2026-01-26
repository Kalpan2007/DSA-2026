// 1st Appproch With Recursion Fail With TLE

// class Solution {
// public:

// bool solve(vector<int> nums , int n , int i){
//     if(i == n-1) return true;
//     for(int j = 1 ; j <= nums[i] ; j++){
//         if(solve(nums,n,i+j)==true) return true;
//     }
//     return false;
// }

//     bool canJump(vector<int>& nums) {
//         int n = nums.size();
//         return solve(nums , n, 0);
//     }
// };


// 2nd approch with recursion + memoization with TLE
// class Solution {
// public:
//     int t[10001];

//     bool solve(vector<int> nums, int n, int i) {
//         if (i == n - 1)
//             return true;
//         if (t[i] != -1)
//             return t[i];
//         for (int j = 1; j <= nums[i]; j++) {
//             if (solve(nums, n, i + j) == true)
//                 return t[i] = true;
//         }
//         return t[i] = false;
//     };

//     bool canJump(vector<int>& nums) {
//         int n = nums.size();
//         memset(t, -1, sizeof(t));
//         return solve(nums, n, 0);
//     }
// };


// 3rd Approch With Greedy O(n) time and O(1) space
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxidx = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(i>maxidx) return false;
            maxidx = max(maxidx , i + nums[i]);
        }
        return true;
    }
};