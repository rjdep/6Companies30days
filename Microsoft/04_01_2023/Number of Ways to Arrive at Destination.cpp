class Solution {
public:
    const int MOD = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> dist(n,1e18), path(n,0);
        vector<vector<pair<int,int>>> g(n);
        for(int i=0; i<roads.size(); i++){
            g[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            g[roads[i][1]].push_back({roads[i][0],roads[i][2]});

        }
        priority_queue<pair<long long,int>> pq;
        pq.push({0,0});
        dist[0]=0;
        path[0]=1;
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int node = cur.second;
            long long d = -cur.first;
            for(auto x: g[node]){
                if(dist[x.first]>d + x.second){
                    dist[x.first]=d+x.second;
                    pq.push({-dist[x.first],x.first});
                    path[x.first]=path[node];
                }else if(dist[x.first]==d+x.second){
                    path[x.first]= (path[x.first] + path[node]);
                    if(path[x.first]>=MOD) path[x.first]-=MOD;
                }
            }
        }
        
        return path[n-1];
    }
};
