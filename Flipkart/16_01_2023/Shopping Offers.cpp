class Solution {
public:
    int fans;
    void rec(vector<int> &pr, vector<vector<int>> &sp, vector<int> &need, int sum, int cnt){
        // int s = 0;
        // for(int i=0; i<need.size(); i++){
        //     s += need[i];
        // }

        if(cnt==0){
            fans = min(fans,sum);
            return;
        }
        if(sum>fans) return;
        for(int i=0; i<sp.size(); i++){
            bool f = true;
            for(int j=0; j<need.size(); j++){
                if(sp[i][j]>need[j]){
                    f = false;
                    break;
                }
            }
            if(f){
                int quant = 0;
                for(int j=0; j<need.size(); j++){
                    need[j]-=sp[i][j];
                    quant+=sp[i][j];
                }
                rec(pr,sp,need,sum+sp[i].back(),cnt-quant);
                for(int j=0; j<need.size(); j++){
                    need[j]+=sp[i][j];
                }
            }
        }
        int res = 0;
        for(int i=0; i<need.size(); i++){
            res += need[i]*pr[i];
        }
        fans = min(fans,sum+res);
        return;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        fans = 1e9;
        int cnt = 0;
        for(auto x: needs){
            cnt+=x;
        }
        rec(price,special,needs,0,cnt);
        return fans;
    }
};
