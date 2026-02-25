class Solution {
public:
    bool can_eat_banana(vector<int>& p, int mid, int h) {
        int hours = 0;
        for(int i = 0;i<p.size() ; i++){
            hours += p[i] / mid;
            if(p[i]%mid != 0){
                hours++;
            }
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& p, int h) {
        int n = p.size();
        int l = 1;
        int r = *max_element(p.begin(), p.end());

        while (l < r) {
            int mid = (l + r) / 2;
            if (can_eat_banana(p, mid, h)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};