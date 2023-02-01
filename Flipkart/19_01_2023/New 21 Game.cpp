class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k==0 || n>= k+maxPts) return 1.0;

        // dp[i]-> probability with i points
        // ans = dp[n]+dp[n-1]+..+dp[k]
        vector<double> dp(n+1,0.0);
        dp[0]=1.0;
        // n = 21, k = 18, maxPts = 6
        // dp[1] = dp[0]*p(1) = 0.1
        // dp[2] = dp[2-1]*p(1) + dp[2-2]*p(2) = 1.01/10 = 0.101
        // dp[3] = dp[3-1]*p(1) + dp[3-2]*p(2) + dp[3-3]*p(3)
        // dp[3] = dp[3-1]*p(1) + dp[3-2]*p(2) + dp[3-3]*p(3)
        // dp[4] = dp[4-1]*p(1) + dp[4-2]*p(2) + dp[4-3]*p(3) + dp[4-4]*p(4)
        // dp[5] = dp[5-1]*p(1) + dp[5-2]*p(2) + dp[5-3]*p(3) + dp[5-4]*p(4) + dp[5-5]*p(5)
        // dp[6] = dp[6-1]*p(1) + dp[6-2]*p(2) + dp[6-3]*p(3) + dp[6-4]*p(4) + dp[6-5]*p(5) + dp[6-6]*p(6)
        //         dp[5] + dp[4] + dp[3] + dp[2] + dp[1] + dp[0]
        // dp[7] = dp[7-1]*p(1) + dp[7-2]*p(2) + dp[7-3]*p(3) + dp[7-4]*p(4) + dp[7-5]*p(5) + dp[7-6]*p(6)
        //         dp[6] + dp[5] + dp[4] + dp[3] + dp[2] + dp[1]
        // dp[8] = dp[7] + ... + dp[2]
        // dp[17] = dp[16]*p(1) + dp[15]*p(2) + dp[14]*p(3) +..+ dp[11]*p(6)
        // dp[18] = dp[17]*p(1) +..+ dp[12]*p(6)
        // dp[19] = dp[17]*p(2) + dp[]
        // dp[20]
        // dp[21] = dp[17]*p(4) + dp[16]*p(5) + dp[15]*p(6)
        // dp[10] = dp[10-1]*p(1) + dp[10-2]*p(2) + dp[10-3]*p(3) + dp[10-4]*p(4) + dp[10-5]*p(5) + dp[10-maxPts]*p(maxPts);
        double t = 1.0/maxPts;
        double prev = dp[0]*t;
        // cout<<t<<endl;
        // cout<<prev<<endl;
        for(int i=1; i<=n; i++){
            if(i-maxPts>0) prev -= dp[i-maxPts-1]*t;
            dp[i]=prev;
            if(i<k) prev+=dp[i]*t;
            // cout<<dp[i]<<" "<<prev<<endl; 
        }
        double ans = 0.0;
        for(int i=n; i>=k; i--){
            ans += dp[i];
        }
        // if(n && k==0) ans-=dp[0];
        return ans;

    }
};
