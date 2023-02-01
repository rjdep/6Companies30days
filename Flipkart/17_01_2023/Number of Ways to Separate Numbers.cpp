class Solution {
public:
    int numberOfCombinations(string num) {
       int n = num.length();
       int MOD = 1e9+7;
       vector<vector<int>> dp(n+10,vector<int> (n+10,0)), pre(n+1,vector<int> (n+1,0));
       for(int i=n-2; i>=0; i--){
           for(int j=i+1; j<n; j++){
               if(num[i]==num[j]){
                   dp[i][j]=1+dp[i+1][j+1];
               }
           }
       }        
    //    for(int i=n-1; i>=0 ;i--){
    //        for(int j=i-1; j>=0 ;j--){
    //            cout<<i<< " " <<j<<" "<<dp[i][j]<<endl;
    //        }
    //    } 
        
       for(int i=0; i<n; i++){
        //    if(i &/e;}
       	for(int l=1; l<=i+1; l++){
       		int j = i-l+1;
            //    if(j==0)continue;
       		int sum = 0;
       		if(num[j]=='0'){
       			sum = 0;
       		}else if(j==0){
       			sum=1;
       		}else{
       			int mxLen = 0;
       			if(j<l){
       				mxLen = j;
       			}else if(dp[j-l][j]>=l || (num[j-l+dp[j-l][j]]<num[j+dp[j-l][j]])){ // s[j-l,...,j-1] <= s[j,...,i]
       				mxLen = l;
       			}else{
       				mxLen = l-1;
       			}
       			sum = pre[j-1][mxLen];
       		}
       		pre[i][l]=pre[i][l-1]+sum;
       		pre[i][l]%=MOD;
       	}
       }



       return pre[n-1][n]%MOD;    
    }
};
