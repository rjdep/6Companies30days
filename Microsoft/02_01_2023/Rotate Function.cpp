class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
       int n = nums.size();
       int sum = 0;
       int ans = 0;
       for(int i=0; i<n; i++){
           sum += nums[i];
           ans += (i*nums[i]);
       }
       int res = ans;
       for(int i=n-1; i>0; i--){
           ans = (ans+sum-n*nums[i]);
           res = max(res,ans);
       }
       return res;

    }
};
