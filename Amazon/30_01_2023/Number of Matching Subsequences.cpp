class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<int,vector<int>> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]-'a'].push_back(i);
        }
        int ans=0;
        for(auto x: words){
            int pos=-1;
            bool flag=1;
            for(int i=0; i<x.length(); i++){
                auto it = upper_bound(mp[x[i]-'a'].begin(), mp[x[i]-'a'].end(),pos);
                if(it==mp[x[i]-'a'].end()){
                    flag=0;
                    break;
                }
                pos=*it;
            }
            if(flag){
                ans++;
            }
        }
        return ans;
    }
};
