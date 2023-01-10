class Solution {
public:
    int maximumGood(vector<vector<int>>& ar) {
        int n = ar.size();
        int ans = 0;
        for(int i=0; i<(1LL<<n); i++){
            vector<int> br(n,0),cr(n,0);
            int cnt = 0;
            for(int j=0; j<n; j++){
                if((i & (1LL<<j))){
                    br[j]=1;
                    cnt++;
                }
            }
            bool f = true;
            for(int i=0; i<n; i++){
                if(br[i]==0) continue;
                for(int j=0; j<n; j++){
                    if(i!=j){
                        if(ar[i][j]==0){
                            if(br[j] != 0){
                                f = false;
                                break;
                            }
                        }else if(ar[i][j]==1){
                            if(br[j] != 1){
                                f = false;
                                break;
                            }
                        }
                    }
                }
                if(!f) break;
            }
            // cout<<f<<" "<<ans<<" "<<cnt<<endl;
            if(f){
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};
