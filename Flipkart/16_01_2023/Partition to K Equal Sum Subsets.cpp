class Solution {
public:

    bool rec(vector<int> &nums, vector<int> &vis, int req, int sum, int k, int idx){
        if(k==1){
            return true;
        }
        if(req==sum) return rec(nums,vis,req,0,k-1,0);
        if(idx==nums.size()) return false;
        for(int j=idx; j<nums.size(); j++){
            if(vis[j] || sum+nums[j]>req) continue;
            vis[j]=1;
            if(rec(nums,vis,req,sum+nums[j],k,j+1)){
                return true;
            }
            vis[j]=0;
            while(j+1<nums.size() && nums[j]==nums[j+1]) j++;
        }
        return false;

    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto x: nums){
            sum+=x;
        }
        if(sum%k != 0) return false;
        int res = sum/k;
        int n = nums.size();
        vector<int> vis(n,0);
        sort(nums.begin(),nums.end());
        return rec(nums,vis,res,0,k,0);        
    }

};
