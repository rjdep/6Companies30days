class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& s) {
        int lo=bottom;
        int hi=top;
        sort(s.begin(),s.end());
        int n = s.size();
        int ans = max(s[0]-bottom,top-s[n-1]); 
        for(int i=1; i<n; i++){
            ans = max(ans,s[i]-s[i-1]-1);
        }
        // ans = max({ans,s[0]-bottom,top-s[n-1]});
        return ans;
    }
};
