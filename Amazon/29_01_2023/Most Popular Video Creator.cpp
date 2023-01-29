class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        vector<pair<long long,string>> v;
        int n = creators.size();
        map<string,long long> mp;
        map<string,pair<int,string>> ump;
        for(int i=0; i<n; i++){
            mp[creators[i]]+=views[i];
            if(ump.find(creators[i]) == ump.end()){
                ump[creators[i]]=make_pair(views[i],ids[i]);
            }else{
                if(views[i]>ump[creators[i]].first){
                    ump[creators[i]]=make_pair(views[i],ids[i]);
                }else if(views[i]==ump[creators[i]].first){
                    if(ids[i]<ump[creators[i]].second){
                        ump[creators[i]]=make_pair(views[i],ids[i]);
                    }
                }
            }
        }
        for(auto x: mp){
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        vector<vector<string>> ans;
        long long t = v[0].first;
        for(auto x: v){
            if(x.first==t){
                ans.push_back({x.second,ump[x.second].second});
            }
        }
        return ans;

    }
};
