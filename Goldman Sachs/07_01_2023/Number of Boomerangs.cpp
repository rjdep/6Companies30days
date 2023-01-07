class Solution {
public:

    int dist(vector<int> &a, vector<int> &b){
        return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
    }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        int cnt = 0;
        int n = points.size();
        for(int i=0; i<n; i++){
            map<int,int> mp;
            for(int j=0; j<n; j++){
                if(i!=j){
                    int a = dist(points[i],points[j]);
                    mp[a]++;
                }
            }
            for(auto x: mp){
                int y = x.second;
                cnt+=(y-1)*(y);
            }
        }
        return cnt;
    }
};
