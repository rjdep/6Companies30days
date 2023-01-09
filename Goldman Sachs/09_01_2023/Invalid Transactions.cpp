class Solution {
public:
    vector<string> invalidTransactions(vector<string>& t) {
        vector<string> ans;
        int n = t.size();
        vector<int> arr(n,1);
        for(int i=0; i<n; i++){
            string x = t[i];
            int cnt = 0;
            int num = 0;
            for(auto y:x){
                if(y==','){
                    cnt++;
                }else{
                    if(cnt==2){
                        num = num*10 + (y-'0');
                    }
                }
            }
            if(num>1000){
                arr[i]=-1;
            }
        }

        for(int i=0; i<n; i++){
            // if(arr[i]==-1) continue;
            string name = "", city="";
            int amt = 0, cnt = 0, time = 0;
            for(auto x:t[i]){
                if(x==','){
                    cnt++;
                }else{
                    if(cnt==0){
                        name += x;
                    }else if(cnt==1){
                        time = time*10+(x-'0');
                    }else if(cnt==3){
                        city += x;
                    }
                }
            }
            for(int j=0; j<n; j++){
                if(i==j) continue;
                 string nam = "", cit="";
            int cnt1 = 0, tim = 0;
            for(auto x:t[j]){
                if(x==','){
                    cnt1++;
                }else{
                    if(cnt1==0){
                        nam += x;
                    }else if(cnt1==1){
                        tim = tim*10+(x-'0');
                    }else if(cnt1==3){
                        cit += x;
                    }
                }
            }
            if(name==nam && city != cit){
                if(abs(tim-time)<=60){
                    arr[i]=0;
                    arr[j]=0;
                }
            }
            }
        }

        for(int i=0; i<n; i++){
            if(arr[i] != 1){
                ans.push_back(t[i]);
            }
        }
        return ans;

    }
};
