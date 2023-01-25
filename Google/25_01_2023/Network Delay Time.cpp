class Solution {
public:
    int networkDelayTime(vector<vector<int>>& tt, int n, int k) {
        vector<vector<pair<int,int>>> g(n+1);
        for(int i=0; i<tt.size(); i++){
            g[tt[i][0]].push_back({tt[i][1],tt[i][2]});
        }
        int dist[n+1];
        for(int i=1; i<=n; i++) dist[i]=1e9;
        priority_queue<pair<int,int>> pq;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            for(auto x: g[cur.second]){
                if(dist[x.first]>dist[cur.second]+x.second){
                    dist[x.first]=dist[cur.second]+x.second;
                    pq.push({-dist[x.first],x.first});
                }
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++){
            ans = max(ans,dist[i]);
        }
        if(ans==1e9){
            return -1;
        }else{
            return ans;
        }
        
    }
};
