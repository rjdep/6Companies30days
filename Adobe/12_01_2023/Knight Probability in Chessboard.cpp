class Solution {
public:
long double dp[50][50][200];
int n;
int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

long double rec(int i, int j, int k){
	if(k==0) return 1.0;
	if(dp[i][j][k] != -1) return dp[i][j][k];
	long double ans = 0;
	for(int x=0; x<8; x++){
		int newx = i+dx[x], newy = j+dy[x];
		if(newx>=0 && newx<n && newy>=0 && newy<n){
			ans += rec(newx,newy,k-1);
		}
	}
	return dp[i][j][k]=ans/8.0;
}

    double knightProbability(int nn, int k, int row, int column) {
        n = nn;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                for(int kk=0; kk<=k; kk++){
                    dp[i][j][kk]=-1;
                }
            }
        }
        return rec(row,column,k);
    }
};
