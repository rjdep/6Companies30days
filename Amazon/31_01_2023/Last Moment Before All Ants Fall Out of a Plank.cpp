class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int lf = 0, rt = n;
        for(auto x: left){
            lf = max(lf,x);
        }
        for(auto y: right){
            rt = min(rt,y);
        }
        rt = n-rt;
        return max(rt,lf);

    }
};
