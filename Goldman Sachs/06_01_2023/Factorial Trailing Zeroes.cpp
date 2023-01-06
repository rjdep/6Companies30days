class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        long long rem = 5;
        while(1){
            int temp = n/rem;
            if(temp==0) break;
            cnt += temp;
            rem *= 5;
        }
        return cnt;
    }
};
