class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int>last(26);
        for(int i = 0 ; i<n ;i++){
            last[s[i]-'a']=i;
        }
        int rightMost =-1;
        vector<int>ans;
        int start =0;
        for(int i =0 ;i<n ;i++){
            rightMost =max(rightMost,last[s[i]-'a']);
            if(i==rightMost){
                ans.push_back(rightMost-start+1);
                start =rightMost+1;
            }
        }
        return ans;
    }
};