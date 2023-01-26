class Solution {
public:

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    void dfs(int x, int y, int mid, vector<vector<int>>& grid, vector<vector<int>>& vis){
        if(grid[x][y]>mid) return;
        vis[x][y]=1;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<4; i++){
            int xx = x+dx[i], yy = y+dy[i];
            if(xx>=0 && xx<n && yy>=0 && yy<m && !vis[xx][yy] && grid[xx][yy]<=mid){
                dfs(xx,yy,mid,grid,vis);
            }
        }
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int lo=0,hi=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                hi=max(hi,grid[i][j]);
            }
        }

        int ans = 0;
        vector<vector<int>> vis(n+1,vector<int> (m+1,0));
        while(lo<=hi){
            int mid = (lo+hi)/2;
            vis = vector<vector<int>> (n+1,vector<int>(m+1,0));
            dfs(0,0,mid,grid,vis);
            if(vis[n-1][m-1]){
                ans = mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;

    }
};
