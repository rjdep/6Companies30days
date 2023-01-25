class Solution {
public:
    multiset<pair<int,int>> mt;
    int s;
    Solution(vector<int>& w) {
        mt.clear();
        s = 0;
        for(int i=0; i<w.size(); i++){
            s += w[i];
            mt.insert({s,i});
        }    
    }
    
    int pickIndex() {
        int r = (rand()%(s))+1;
        auto it = mt.lower_bound({r,-1});
        return (*it).second;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
