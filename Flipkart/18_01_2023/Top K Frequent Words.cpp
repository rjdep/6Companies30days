class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(auto x: words) mp[x]++;
        priority_queue<pair<int,string>> pq;
        for(auto x: mp){
            pq.push({-x.second,x.first});
            if(pq.size()>k) pq.pop();
        }
        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
