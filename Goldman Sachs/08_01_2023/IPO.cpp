class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> v;
        int n = profits.size();
        for(int i=0; i<n; i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<int> cap,pro;
        int ans = w;
        for(int i=0; i<n; i++) cap.push(-i);
        while(1){
            int mx = ans;
            while(!cap.empty() && v[-cap.top()].first<=ans){
                pro.push(v[-cap.top()].second);
                cap.pop();
            }
            if(k>0){
                if(!pro.empty()){
                    ans += pro.top();
                    pro.pop();
                    k--;
                }
            }
            if(mx==ans || k==0) break;
        }
        return ans;
    }
};
