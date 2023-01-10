class Solution {
public:
    int rev(int n){
        if(n==0) return n;
        while(n%10==0){
            n/=10;
        }
        long long num = 0;
        while(n){
            int rem = n%10;
            num = num*10 + rem;
            n/=10;
        }
        return num;
    }
    int countNicePairs(vector<int>& nums) {
        map<int,int> mp;
        for(auto x: nums){
            mp[x-rev(x)]++;
        }
        long long cnt = 0;
        int MOD = 1e9+7;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]-rev(nums[i])]--;
            cnt = cnt+mp[nums[i]-rev(nums[i])];
            cnt%=MOD;
        }
        return cnt;
    }
};
