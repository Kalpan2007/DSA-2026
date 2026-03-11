class Solution {
public:
    string numberToBinaryCustom(int n) {
        if (n == 0)
            return "0";
        string binary_str = "";
        while (n > 0) {
            int remainder = n % 2;
            binary_str += to_string(remainder);
            n /= 2;
        }
        reverse(binary_str.begin(), binary_str.end());
        return binary_str;
    }
    
    int bitwiseComplement(int n) {
        string bn = numberToBinaryCustom(n);
        for(int i = 0 ; i < bn.size() ; i++){
            if(bn[i]=='1'){
                bn[i] = '0';
            }else{
                bn[i] = '1';
            }
        }
        cout << bn << endl;
        int ans = stoi(bn, nullptr, 2); 
        return ans;
    }
};