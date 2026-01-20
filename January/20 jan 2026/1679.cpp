class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int count = 0;

        for (int x : nums) {
            int need = k - x;

            if (freq[need] > 0) {
                count++;
                freq[need]--;
            } else {
                freq[x]++;
            }
        }
        return count;
        
    }
};