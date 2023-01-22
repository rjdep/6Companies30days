class Solution {
public:
    int maximumGood(vector<vector<int>>& s) {
        int n = s.size();
        int ans = 0;
        for(int i=0; i<(1LL<<n); i++){
            int cnt = 0;
            vector<int> br(n,0);
            for(int j=0; j<n; j++){
                if(i&(1LL<<j)){
                    cnt++;
                    br[j]=1;
                }
            }
            bool f = true;
            for(int j=0; j<n; j++){
                if(br[j]){
                    for(int k=0; k<n; k++){
                        if(j!=k){
                            if((s[j][k]==1 && br[k]==0) || (s[j][k]==0 && br[k]==1)){
                                f = false;
                                break;
                            }
                        }
                        if(!f) break;
                    }
                }
                    if(!f) break;
            }
            if(f) ans = max(ans,cnt);
        }
        return ans;
    }
};
