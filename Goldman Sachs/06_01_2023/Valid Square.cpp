class Solution {
public:

    int cal(vector<int> a, vector<int> b){
        return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<int,int> mp;
        vector<vector<int>> v(4);
        v[0]=p1,v[1]=p2,v[2]=p3,v[3]=p4;
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(j!=i)
                mp[cal(v[i],v[j])]++;
            }
        }
        if(mp.size() != 2) return false;
        vector<pair<int,int>> pr;
        for(auto x: mp){
            pr.push_back({x.first,x.second});
        }
        if(pr[1].first != 2*pr[0].first) return false;
        if(pr[1].second != 4 && pr[0].second != 8) return false;
        return true;

    }
};
