class Solution {
public:

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    bool f;

    void dfs(int x, int y, vector<vector<int>>& grid,vector<vector<int>> &vis, int n, int m){
        // if(x<0 || x>=n || y<0 || y>=m) return;
        if(x==0 || x==n-1 || y==0 || y==m-1){
            f = false;
        }
        vis[x][y]=1;
        for(int i=0; i<4; i++){
            int xx = x+dx[i], yy = y+dy[i];
            if(xx>=0 && xx<n && yy>=0 && yy<m && grid[xx][yy]==0 && !vis[xx][yy]){
                dfs(xx,yy,grid,vis,n,m);
            }
        }
        // return;

    }

    int closedIsland(vector<vector<int>>& grid) {
        int cnt = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n+1,vector<int> (m+1,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                f = true;
                if(!vis[i][j] && grid[i][j]==0){
                    dfs(i,j,grid,vis,n,m);
                    if(f) cnt++;
                }
            }
        }
        return cnt;
    }
};
