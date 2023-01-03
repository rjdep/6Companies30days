class Solution {
public:
    
    vector<vector<int>> g;
    vector<int> vis, topo;
    void dfs(int node){
        vis[node]=1;
        for(auto v: g[node]){
            if(!vis[v]){
                dfs(v);
            }
        }
        topo.push_back(node);
    }
    
    
    bool canFinish(int n, vector<vector<int>>& p) {
        g.clear();
        topo.clear();
        g.resize(n);
        vis.assign(n,0);
        for(auto x: p){
            g[x[1]].push_back(x[0]);
        }
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i);
            }
        }
        int arr[n];
        reverse(topo.begin(),topo.end());
        for(int i=0; i<topo.size(); i++){
            arr[topo[i]]=i;
            // cout<<topo[i]<<" ";
        }
        // cout<<endl;
        bool flag=true;
        for(int i=0; i<p.size(); i++){
            if(arr[p[i][0]]<=arr[p[i][1]]){
                flag = false;
                break;
            }
        }
        return flag;
        
    }
};
