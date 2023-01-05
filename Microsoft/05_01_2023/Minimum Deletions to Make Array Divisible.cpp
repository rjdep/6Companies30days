class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& div) {
        int x = div[0];
        int n = div.size();
        for(int i=1; i<n; i++){
            x = __gcd(x,div[i]);
        }
        cout<<x<<endl;
        vector<int> factors;
        factors.push_back(1);
        for(int i=2; i*i<=x; i++){
            if(x%i==0){
                factors.push_back(i);
                if(i*i!=x){
                    factors.push_back(x/i);
                }
            }
        }
        factors.push_back(x);
        set<int> st;
        for(auto x: nums){
            st.insert(x);
        }
        sort(factors.begin(),factors.end());
        int ans = -1;
        for(auto x: factors){
            if(st.find(x) != st.end()){
                ans = x;
                break;
            }
        }
        cout<<ans<<endl;
        if(ans==-1){
            return -1;
        }
        int cnt = 0;
        for(auto x:nums){
            if(x<ans){
                cnt++;
            }
        }
        return cnt;
        
    }
};
