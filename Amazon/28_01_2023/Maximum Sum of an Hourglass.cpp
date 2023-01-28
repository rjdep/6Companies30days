class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<=n-3; i++){
            for(int j=0; j<=m-3; j++){
                int cur = grid[i][j]+grid[i][j+1]+grid[i][j+2]+grid[i+1][j+1]+grid[2+i][j]+grid[2+i][j+1]+grid[i+2][j+2];   
                ans = max(ans,cur);
            }
        }
        return ans;
    }
};
