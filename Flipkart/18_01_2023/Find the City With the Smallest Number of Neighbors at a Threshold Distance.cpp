class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int tt) {
        vector<vector<int>> dist(n+1,vector<int>(n+1,1e9));
        for(auto x: edges){
            dist[x[0]][x[1]]=x[2];
            dist[x[1]][x[0]]=x[2];
        }
        for(int i=0; i<n; i++){
            dist[i][i]=0;
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        int ans = 0, num = 1e9;
        for(int i=n-1; i>=0; i--){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(i!=j && dist[i][j]<=tt){
                    cnt++;
                }
            }
            // cout<<i<<" "<<cnt<<endl;
            if(cnt<num){
                num = cnt;
                ans = i;
            }
        }
        return ans;

    }
};
