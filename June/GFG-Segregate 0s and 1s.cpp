class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int i =0;
        int j = arr.size()-1;
        while(i < j){
            if(arr[j]!=0){
                while(arr[j]!=0 && i < j){
                    j--;
                }
            }
            if(arr[i]==1 && i < j){
                swap(arr[i] , arr[j]);
            }
            i++;
        }
    }
};