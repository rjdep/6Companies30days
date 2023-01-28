class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int MOD = 1e9+7;
        stack<pair<int,int>> st;
        int n = nums.size();
        vector<int> lf(n), rt(n);
        for(int i=0; i<n; i++){
            int cnt = 1;
            while(!st.empty() && nums[i]<=nums[st.top().first]){
                cnt += st.top().second;
                st.pop();
            }
            lf[i]=cnt;
            st.push({i,cnt});
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
            int cnt = 1;
            while(!st.empty() && nums[i]<=nums[st.top().first]){
                cnt += st.top().second;
                st.pop();
            }
            rt[i]=cnt;
            st.push({i,cnt});
        } 
        long long ans = 0;
        vector<long long> pref(n,nums[0]);
        for(int i=1; i<n; i++){
            pref[i]=pref[i-1]+nums[i];
        }
        // for(int i=0; i<n; i++){
        //     cout<<lf[i]<<" ";
        // }cout<<endl;

        // for(int i=0; i<n; i++){
        //     cout<<rt[i]<<" ";
        // }cout<<endl;

        for(int i=0; i<n; i++){
            int l = i-lf[i]+1;
            int r = i+rt[i]-1;
            long long cur = pref[r]-((l==0)?0:(pref[l-1]));
            // cout<<pref[r]<<endl;
            // cout<<l<<" "<<r<<endl;
            ans = max(ans,cur*nums[i]);
        }       
        return ans%MOD;
    }
};
