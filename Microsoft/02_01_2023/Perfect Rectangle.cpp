class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rect) {
        map<pair<int,int>,int> mp;
        for(auto x: rect){
            mp[{x[0],x[1]}]++;
            mp[{x[2],x[3]}]++;
            mp[{x[0],x[3]}]--;
            mp[{x[2],x[1]}]--;
        }
        int cnt = 0;
        for(auto x: mp){
            if(x.second != 0){
                cnt+=abs(x.second);
            }
        }
        if(cnt==4) return true;
        return false;
    }
};
