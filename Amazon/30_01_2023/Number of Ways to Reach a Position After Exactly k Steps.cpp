class Solution {
public:
    int MOD = 1e9+7;
    int rec(int pos, int cnt, vector<vector<int>> &dp, int st, int en, int k){
        if(pos==en && cnt==k) return 1;
        if(dp[pos][cnt]!=-1) return dp[pos][cnt];
        int ans = 0;
        if(cnt<k){
            ans = (rec(pos+1,cnt+1,dp,st,en,k)%MOD+rec(pos-1,cnt+1,dp,st,en,k)%MOD)%MOD;
        }
        return dp[pos][cnt]=ans;
    }

    int numberOfWays(int startPos, int endPos, int k) {
        startPos+=1500;
        endPos+=1500;
        vector<vector<int>> dp(3550,vector<int>(k+1,-1));
        return rec(startPos,0,dp,startPos,endPos,k);
    }
};
