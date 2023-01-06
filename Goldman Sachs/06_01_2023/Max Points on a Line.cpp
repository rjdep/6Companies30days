class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        vector<vector<int>> v;
        int n = points.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int ax = points[i][0], ay = points[i][1];
                int bx = points[j][0], by = points[j][1];
                v.push_back({bx-ax, by-ay, by*(bx-ax)-bx*(by-ay)});
            }
        }
        int cnt = 1;
        for(auto x: v){
            int res = 0;
            for(int i=0; i<n; i++){
                if(x[0]*points[i][1]-x[1]*points[i][0]==x[2]){
                    res++;
                }
            }
            cnt=max(cnt,res);
        }
    return cnt;
    }
};
