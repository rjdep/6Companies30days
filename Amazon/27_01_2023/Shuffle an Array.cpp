class Solution {
public:

    vector<int> cur, idx;
    int n;
    Solution(vector<int>& nums) {
        idx = nums;
        cur = idx;
        n = nums.size();
    }
    
    vector<int> reset() {
        cur = idx;
        return cur;
    }
    
    vector<int> shuffle() {
        for(int i=n-1; i>=0; i--){
            int j = rand()%n;
            swap(cur[i],cur[j]);
        }
        return cur;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
