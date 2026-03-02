class Solution {
public:
typedef long long ll;
    int calculate(string s) {
        stack<int> st;
    ll ans = 0;
    ll num = 0;
    ll sign = 1;

    for (char ch : s) {

        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
        }

        else if (ch == '+') {
            ans += sign * num;
            num = 0;
            sign = 1;
        }

        else if (ch == '-') {
            ans += sign * num;
            num = 0;
            sign = -1;
        }

        else if (ch == '(') {
            st.push(ans);   
            st.push(sign);  
            ans = 0;
            sign = 1;
        }

        else if (ch == ')') {
            ans += sign * num;
            num = 0;

            ans *= st.top(); st.pop(); 
            ans += st.top(); st.pop(); 
        }
    }

    ans += sign * num;
    return (int)ans;
    }
};