class Solution {
public:
    int findIntegers(int n) {
    vector<int> dp(32,0);
    dp[0]=1;
	dp[1]=2,dp[2]=3;
	for(int i=3; i<32; i++){
		dp[i]=dp[i-1]+dp[i-2];
	}	
	// show(dp);
	// ll n; cin>>n;
	long long ans = 0;
	int bit = log2(n);
	// cout<<bit<<endl;
	int prev = 0;
	for(int i=30; i>=0; i--){
		if(n&(1LL<<i)){
			ans += dp[i];
			if(prev) ans;
			prev = 1;
		}else{
			prev = 0;
		}
	}
	// cout<<ans<<endl;
    return ans+1;
    }
};
