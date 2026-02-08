class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
      unordered_map<int,int>mp;
      for(auto x: arr){
          mp[x]++;
      }  
      
      unordered_set<int>s;
      for(auto x: mp){
          s.insert(x.second);
      }

      return mp.size()==s.size();
    }
};


