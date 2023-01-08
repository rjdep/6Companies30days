class Solution {
public:

    vector<int> temp,ans;
    int finans;
    void rec(int level, int sum, vector<int> &res, vector<int> &arr){
        if(level==12){
            int cnt = 0;
            for(auto x:res){
                cnt += x;
            }
            if(cnt>finans){
                finans = cnt;
                ans = res;
            }
            return;
        }
        for(int i=level; i<12; i++){
            if(sum>arr[i]){
                res.push_back(i);
                rec(i+1,sum-arr[i]-1,res,arr);
                res.pop_back();
            }else{
                rec(i+1,sum,res,arr);
            }
        }
    }

    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> pseudo;
        finans = 0;
        ans.clear();
        rec(0,numArrows,pseudo,aliceArrows);
        vector<int> req(12);
        for(auto x: ans){
            req[x]=aliceArrows[x]+1;
            numArrows-=req[x];
        }
        if(numArrows){
            for(int i=0; i<12; i++){
                if(req[i]){ req[i]+=numArrows;
                    break;
                }
            }
        }
        return req;
    }
};
