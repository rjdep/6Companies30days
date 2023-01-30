class Solution {
public:

    
    bool check(vector<int> &nums1, vector<int> &nums2, int mid){
        set<vector<int>> st;
        int n = nums1.size(), m = nums2.size();
        if(mid>n || mid>m) return false;
        for(int i=0; i<=n-mid; i++){
            vector<int> temp;
            for(int j=i; j<min(n,i+mid); j++){
                temp.push_back(nums1[j]);
            }
            st.insert(temp);
        }
        for(int j=0; j<=m-mid; j++){
            vector<int> temp;
            for(int i=j; i<min(m,j+mid); i++){
                temp.push_back(nums2[i]);
            }
            if(st.find(temp) != st.end()) return true;
        }
        return false;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int len = 0, n = nums1.size(), m = nums2.size();
        int lo=0, hi=min(n,m);
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check(nums1,nums2,mid)){
                len = mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return len;
    }
    
    /*
    int dp[1010][1010];
    int rec(int l, int r, vector<int> &nums1,vector<int> &nums2){
        if(l==nums1.size() || r==nums2.size()) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int ans = 0;
        if(nums1[l]==nums2[r]){
            ans = 1+rec(l+1,r+1,nums1,nums2);
        }else
            ans = max(rec(l,r+1,nums1,nums2),rec(l+1,r,nums1,nums2));
        
        return dp[l][r]=ans;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                dp[i][j]=-1;
            }
        }
        int ans =0;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                ans = max(ans,rec(i,j,nums1,nums2));//p[i][j]=-1;
                cout<<i<<" "<<j<<" "<<rec(i,j,nums1,nums2)<<endl;
            }
        }
        return ans;
    }
    */
};
