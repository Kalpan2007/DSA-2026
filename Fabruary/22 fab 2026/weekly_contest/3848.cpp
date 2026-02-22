class Solution {
public:
    long long fact(int n){
        long long facto = 1;
        for(int i =1;i<=n;i++){
            facto *= i;
        }
        return facto;
    }
    bool isDigitorialPermutation(int n) {
        vector<int> original_counts(10,0);
        long long fact_sum = 0;
        int temp = n;
        int digits = 0;

        while(temp > 0){
            int last = temp % 10;
            original_counts[last]++;
            fact_sum += fact(last);
            temp /= 10;
            digits++;
        }

        long long temp_sum = fact_sum;

        vector<int> sun_counts(10,0);
        int sum_count = 0;

        while(temp_sum > 0){
            int last_digit = temp_sum %10;
            sun_counts[last_digit]++;
            temp_sum /= 10;
            sum_count++;
        }

        if(digits!=sum_count) return false;

        for(int i = 0;i<10;i++){
            if(original_counts[i] != sun_counts[i]) return false;
        }
        return true;
    }
};