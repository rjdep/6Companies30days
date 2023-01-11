class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n+10,0);
        long long MOD = 1e9+7;
        dp[1]=1;
        long long res = 0;
        for(int i=2; i<=n; i++){
            if(i-delay>=1) dp[i]=(dp[i]+dp[i-delay])%MOD;
            if(i-forget>=1) dp[i]=(dp[i]-dp[i-forget]+MOD)%MOD;
            dp[i] = (res+dp[i])%MOD;
            res = dp[i];
        }
        long long ans = 0;
        for(int i=n; i>n-forget; i--){
            // cout<<dp[i]<<endl;
            ans = (ans+dp[i])%MOD;
        }
        return ans%=MOD;
    }
};
