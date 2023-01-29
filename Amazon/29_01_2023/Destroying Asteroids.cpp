class Solution {
public:
    bool asteroidsDestroyed(int m, vector<int>& a) {
        sort(a.begin(),a.end());
        bool f = true;
        long long mass = m;
        for(auto x: a){
            if(mass<x){
                f = false;
                break;
            }
            mass+=x;
        }
        return f;
    }
};
