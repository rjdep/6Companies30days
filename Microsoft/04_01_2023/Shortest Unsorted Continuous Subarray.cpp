class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int >temp;
        for(auto x: nums){
            temp.push_back(x);
        }
        sort(temp.begin(),temp.end());
        int n = nums.size();
        int idx1 = -1, idx2 = -2;
        for(int i=0; i<n; i++){
            if(nums[i] != temp[i]){
                idx1 = i;
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(nums[i] != temp[i]){
                idx2 = i;
                break;
            }
        }

        return idx2-idx1+1;


    }
};
