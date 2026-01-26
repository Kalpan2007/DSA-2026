class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int dif=INT_MAX;
        unordered_map<int,vector<vector<int>> >mp;
        for(int i=0;i<arr.size()-1;i++){
            mp[arr[i+1]-arr[i]].push_back({arr[i],arr[i+1]});
            dif=min(dif,arr[i+1]-arr[i]);
        }
        return mp[dif];
    }
};