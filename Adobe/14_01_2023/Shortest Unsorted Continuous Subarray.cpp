class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        /*
        vector<int> temp;
        for(auto x: nums) temp.push_back(x);
        sort(temp.begin(),temp.end());
        int idx1 = -1, idx2 = -1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==temp[i]) continue;
            else{
                idx1 = i;
                break;
            }
        }
        if(idx1==-1) return 0;
        for(int i=n-1; i>=0; i--){
            if(nums[i]==temp[i]) continue;
            else{
                idx2 = i;
                break;
            }
        }
        return idx2-idx1+1;
        */

        int n = nums.size();
        int lo=1e9, hi=-1e9;
        for(int i=1; i<n; i++){
            if(nums[i]<nums[i-1]){
                lo=min(lo,nums[i]);
            }
        }
        if(lo==1e9) return 0;
        for(int i=n-2; i>=0; i--){
            if(nums[i]>nums[i+1]){
                hi=max(hi,nums[i]);
            }
        }
        int idx1 = n-1, idx2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i]>lo){
                idx1 = i;
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(nums[i]<hi){
                idx2 = i;
                break;
            }
        }
        return idx2-idx1+1;

        

    }
};
