class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> temp;
        for(auto x: nums){
            if(temp.empty() || temp.back()<x){
                temp.push_back(x);
            }else{
                auto it = lower_bound(temp.begin(),temp.end(),x);
                *it = x;
            }
        }
        return temp.size()>=3;
    }
};
