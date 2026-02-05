class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> result;
        unordered_set<int> set;

        for (int i = 0; i < nums1.size(); i++) {
            set.insert(nums1[i]);
        }

        vector<int> ans1;
        unordered_set<int> used1;
        for (int i = 0; i < nums2.size(); i++) {
            if (!set.count(nums2[i]) && !used1.count(nums2[i])) {
                ans1.push_back(nums2[i]);
                used1.insert(nums2[i]);
            }
        }

       
        set.clear();

        for (int i = 0; i < nums2.size(); i++) {
            set.insert(nums2[i]);
        }

        vector<int> ans2;
        unordered_set<int> used2;

        for (int i = 0; i < nums1.size(); i++) {
            if (!set.count(nums1[i]) && !used2.count(nums1[i])) {
                ans2.push_back(nums1[i]);
                used2.insert(nums1[i]);
            }
        }

        result.push_back(ans2);
         result.push_back(ans1);

        return result;
    }
};
