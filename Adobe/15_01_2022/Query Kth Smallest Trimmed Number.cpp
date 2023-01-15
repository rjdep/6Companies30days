class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto x: queries){
            auto a = x[0], b = x[1];
            vector<pair<string,int>> arr;
            for(int i=0; i<nums.size(); i++){
                string t = nums[i];
                reverse(t.begin(),t.end());
                t = t.substr(0,b);
                reverse(t.begin(),t.end());
                arr.push_back({t,i});
            }
            sort(arr.begin(),arr.end());
            ans.push_back(arr[a-1].second);
        }
        return ans;
    }
};
