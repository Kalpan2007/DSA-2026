class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.length();
        int n2  = word2.length();
        if(n1!=n2){
            return false;
        }
        map<char,int> w1;
        map<char,int> w2;
        for(auto i:word1) w1[i]++;
        for(auto i:word2) w2[i]++;
        for(auto i:word1){
            if(!w2[i]){
                return false;
            }
        }
        
        vector<int> a,b;
      for(auto x:w1) a.push_back(x.second);
        for(auto x:w2) b.push_back(x.second);

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

          if(a==b)
          return true;
          return false;

    }
};