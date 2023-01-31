class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int cnt;
    void dfs(int x, int y,vector<vector<int>> &g, vector<vector<int>> &vis){
        vis[x][y]=1;
        cnt++;
        for(int i=0; i<4; i++){
            int xx = x+dx[i], yy = y+dy[i];
            if(xx>=0 && xx<g.size() && yy>=0 && yy<g[0].size() && !vis[xx][yy] && g[xx][yy]){
                dfs(xx,yy,g,vis);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n+1,vector<int> (m+1,0));
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]){
                    cnt = 0;
                    dfs(i,j,grid,vis);
                    ans = max(ans,cnt);
                }
            }
        }
        return ans;

    }
};

// Original link to the problem of the doc not working.
