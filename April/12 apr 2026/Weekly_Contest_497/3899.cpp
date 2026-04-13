class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        int a = sides[0];
        int b = sides[1];
        int c = sides[2];

        if(a+b <=c || a + c <= b || b + c <=a) return {};

        double A = acos((double)(b*b + c*c - a*a) / (2.0 * b *c));
        
        double B = acos((double) (a*a + c*c - b*b ) / (2.0 * a *c));
        
        double C = acos((double)(b*b +  a*a -  c*c) / (2.0 * b *a));

        double pi = acos(-1.0);
        double da = A * 180.0 / pi;
        double db = B * 180.0 / pi;
        double dc = C * 180.0 / pi;

        vector<double> ans = {da , db , dc};
        sort(ans.begin() , ans.end());
        return ans;
    }
};