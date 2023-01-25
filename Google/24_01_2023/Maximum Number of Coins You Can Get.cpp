class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        reverse(piles.begin(),piles.end());
        int ans = 0;
        int n = piles.size();
        int cnt = n/3;
        for(int i=1; i<n-cnt; i+=2){
            ans += piles[i];
        }
        return ans;
    }
};
