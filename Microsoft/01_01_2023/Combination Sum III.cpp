class Solution {
public:

    set<int> st;
    // vector<int> temp;
    void rec(int n, int k,int idx, vector<int> &temp){
        if(temp.size()==k){
            int sum = 0;
            for(auto x: temp){
                sum+=x;
            }
            if(sum==n){
                int bit = 0;
                for(auto x: temp){
                    bit |= (1<<x);
                }
                if(st.find(bit) == st.end()){
                    st.insert(bit);
                }
            }
        return;
        }
        int sum = 0;
        for(auto x: temp){
            sum+=x;
            if(sum>n) return;
        }
        if(idx==10) return;
        for(int i = idx; i<=9; i++){
            temp.push_back(i);
            rec(n,k,i+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        rec(n,k,1,temp);
        vector<vector<int>> ans;
        for(auto x: st){
            int n = x;
            vector<int> v;
            for(int i=10; i>=0; i--){
                if(n & (1<<i)){
                    v.push_back(i);
                }
            }
            if(!v.empty()){
                ans.push_back(v);
            }
        }
        return ans;
    }
};
