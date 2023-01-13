class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        priority_queue<pair<int,string>> pq;
        set<string> st;
        for(auto x: bank){
            st.insert(x);
        }
        st.insert(start);
        map<string,int> mp;
        set<string> vis;
        pq.push({0,start});
        int n = start.length();
        char arr[4]={'A','T','G','C'};
        int ans = 1e9;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int curcost = -it.first;
            string curstring = it.second;
            if(curstring==end){
            	// cout<<cur<<endl;
                ans = min(curcost,ans);
                break;
            }
            if(vis.find(curstring) != vis.end()){
                continue;
            }
            vis.insert(curstring);
            for(int idx=0; idx<n; idx++){
                for(int i=0; i<4; i++){
                    string res = curstring;
                    res[idx]=arr[i];
                    if(st.find(res)==st.end()) continue;
                    int cs = curcost;
                    if(curstring[idx]!=arr[i]) cs++;
                    if(mp.find(res)!=mp.end()){
                        if(mp[res]>=cs){
                            mp[res]=cs;
                            pq.push({-cs,res});
                        }
                    }else{
                        mp[res]=cs;
                        pq.push({-cs,res});
                    }
                }
            }
        }
        return (ans==1e9?-1:ans);
    }
};
