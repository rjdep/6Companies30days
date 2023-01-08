class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>> v;
        int n = profits.size();
        for(int i=0; i<n; i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end());
        int i = 0;
        int ans = w;
        priority_queue<int> pq;
        while(i<n){
            int mx = ans;
            while(i<n && v[i][0]<=ans){
                pq.push(v[i][1]);
                i++;
            }
            if(!pq.empty() && k>0){
                ans += pq.top();
                pq.pop();
                k--;
            }
            if(k==0 || ans==mx) break;
        }
        while(!pq.empty()){
            if(k==0) break;
            ans += pq.top();
            pq.pop();
            k--;
        }
        return ans;
    }

};
