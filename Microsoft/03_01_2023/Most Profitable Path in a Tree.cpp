class Solution {
public:

    void dfs(int node, int p, vector<vector<int>> &g, vector<int> &par){
        par[node]=p;
        for(auto x: g[node]){
            if(x!=p) dfs(x,node,g,par);
        }
        return;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size()+1;
        vector<vector<int>> g(n);
        for(auto x: edges){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        vector<int> par(n+1);
        dfs(0,-1,g,par);
        vector<int> time(n+1,1e9),vis(n+1,0);
        int node = bob;
        int cnt = 0;
        while(node != -1){
            time[node]=cnt++;
            node = par[node];
        }
        queue<pair<int,int>> q;
        int cost = amount[0];
        // if(time[0]==0){
        //     cost = amount[0]/2;
        // }else if(time[0]>0){
        //     cost = amount[0];
        // }
        q.push({0,cost});
        int ans = -1e9;
        cnt = 1;
        while(!q.empty()){
            int m = q.size();
            while(m--){
                auto it = q.front();
                q.pop();
                if(vis[it.first]) continue;
                vis[it.first]=1;
                if(g[it.first].size()==1 && it.first){
                    ans = max(ans,it.second);
                    continue;
                }
                for(auto x: g[it.first]){
                    if(!vis[x]){
                        int cst = 0;
                        if(time[x]==cnt){
                            cst = amount[x]/2;
                        }else if(time[x]>cnt){
                            cst = amount[x];
                        }else{
                            cst = 0;
                        }
                        q.push({x,cst+it.second});
                    }
                }
            }
            cnt++;
        }
        return ans;
    }
};
