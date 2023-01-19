class Solution {
public:

    bool check(vector<int> &arr){
        for(int i=1; i<arr.size(); i++){
            if(arr[i]==arr[i-1]) return false;
        }
        return true;
    }

    vector<int> rearrangeBarcodes(vector<int>& b) {
        map<int,int> mp;
        for(auto x : b) mp[x]++;
        vector<pair<int,int>> v;
        for(auto x: mp){
            v.push_back({-x.second,x.first});
        }
        sort(v.begin(),v.end());
        b.clear();
        for(auto x: v){
            int cnt = -x.first, num = x.second;
            while(cnt){
                b.push_back(num);
                cnt--;
            }
        }
        int lo=0;
        int n = b.size();
        int hi = (n+1)/2;
        // 1 1 1 2 2  // 1 1 2 2 2
        vector<int> ans;
        while(hi<n){
            ans.push_back(b[lo]);
            ans.push_back(b[hi]);
            lo++;
            hi++;
        }
        if(n%2){
            ans.push_back(b[lo]);
        }

        if(check(ans)) return ans;

        ans.clear();
        lo=0,hi=(n+1)/2;
        while(hi<n){
            ans.push_back(b[hi]);
            ans.push_back(b[lo]);
            lo++;
            hi++;
        }
        if(n%2){
            ans.push_back(b[lo]);
        }
        return ans;

        
    }
};
