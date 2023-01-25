class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<string> st;
        int cnt = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int res = 0;
            string temp = "";
            for(int j=i; j<n; j++){
                if(res==k){
                    if(nums[j]%p==0){
                        break;
                    }else{
                        temp += to_string(nums[j]);
                        temp += ",";
                        st.insert(temp);
                    }
                }else{
                    if(nums[j]%p==0){
                        res++;
                        temp += to_string(nums[j]);
                        temp += ",";
                        st.insert(temp);
                    }else{
                        // res++;
                        temp += to_string(nums[j]);
                        temp += ",";
                        st.insert(temp);
                    }
                }
            }
        } 
        return st.size();
    }
};
