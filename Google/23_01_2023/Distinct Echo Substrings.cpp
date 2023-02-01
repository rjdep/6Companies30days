class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(text[i]==text[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }
            }
        }
        set<string> st;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                // cout<<dp[i][j]<<" "<<i<<" "<<j<<endl;
                if(i+dp[i][j]>=j){
                    st.insert(text.substr(i,j-i));
                }
            }
        }
        return st.size();
    }
};
