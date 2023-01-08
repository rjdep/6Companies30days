class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(auto x: nums) mp[x]++;
        int cnt = n;
        for(int i=0; i<n; i++){
            int x = nums[i];
            if(mp[x] && mp[x+1] && mp[x+2]){
                mp[x]--;
                mp[x+1]--;
                mp[x+2]--;
                x+=3;
                cnt-=3;
            while(mp[x]&&mp[x]>mp[x-1]){
                cnt--;
                mp[x]--;
                x++;
            }
            }
        }
        return cnt==0;
    }
};
