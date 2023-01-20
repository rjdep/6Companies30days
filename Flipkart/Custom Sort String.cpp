class Solution {
public:
    string customSortString(string order, string s) {
        vector<pair<int,int>> v;
        map<int,int> mp;
        for(int i=0; i<order.size(); i++){
            mp[order[i]-'a']=i;
        }
        for(auto x: s){
            v.push_back({mp[x-'a'],x-'a'});
        }
        sort(v.begin(),v.end());
        string ans = "";
        for(auto x: v){
            ans += char(x.second+'a');
        }
        return ans;
    }
};
