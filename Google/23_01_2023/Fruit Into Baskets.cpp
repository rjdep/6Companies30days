class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> mp;
        int lo=0, hi=-1;
        int n = fruits.size();
        int ans = 0;
        while(lo<n){
            while(hi+1<n && ((mp.find(fruits[hi+1]) != mp.end()) || mp.size()<2)){
                hi++;
                mp[fruits[hi]]++;
            }
            ans = max(ans,hi-lo+1);
            if(lo<=hi){
                mp[fruits[lo]]--;
                if(mp[fruits[lo]]==0) mp.erase(mp.find(fruits[lo]));
                lo++;
            }else{
                lo++;
                hi=lo-1;
            }
        }
        return ans;
    }
};
