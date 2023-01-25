class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n,vector<int> (m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(j){
                    mat[i][j] += mat[i][j-1];
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int s = 0;
                for(int r = max(0,i-k); r<=min(n-1,i+k); r++){
                    int a = max(0,j-k);
                    int b = min(m-1,j+k);
                    if(a==0){
                        s += mat[r][b];
                    }else{
                        s += (mat[r][b]-mat[r][a-1]);
                    }
                }
                ans[i][j]=s;                
            }
        }

    return ans;
    }
    
};
