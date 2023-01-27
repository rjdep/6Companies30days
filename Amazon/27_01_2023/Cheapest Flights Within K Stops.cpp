class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        int dp[n+1][k+1];
        for(int i=0; i<=n; i++){
            for(int j=0; j<=k; j++){
                dp[i][j]=-1;
            }
        }
        dp[src][0]=0;
        vector<vector<pair<int,int>>> g(n);
        for(int i=0; i<f.size(); i++){
            g[f[i][0]].push_back({f[i][1],f[i][2]});
        }
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{src,0}});
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int cur_node = cur.second.first;
            int cur_depth = cur.second.second;
            int cur_dist = -cur.first;
            for(auto v: g[cur_node]){
                if(cur_depth<=k){
                    if(dp[v.first][cur_depth]==-1){
                        dp[v.first][cur_depth]=cur_dist+v.second;
                        pq.push({-dp[v.first][cur_depth],{v.first,cur_depth+1}});
                    }else if(dp[v.first][cur_depth]>cur_dist + v.second){
                        dp[v.first][cur_depth]=cur_dist + v.second;
                        pq.push({-dp[v.first][cur_depth],{v.first,cur_depth+1}});
                    }
                }
            }
        }
        int ans = 1e9;
        for(int i=0; i<=k; i++){
            if(dp[dst][i]!=-1) ans = min(ans,dp[dst][i]);
        }
        if(ans==1e9) return -1;
        else return ans;
    }
};
