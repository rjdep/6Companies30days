class Solution {
public:
    int magicalString(int n) {
        if(n<4) return 1;
        string ans = "122";
        // s[i]=='1' --> s[j]=='1' add '2' / s[j]=='2' add '1'
        // s[i]=='2' --> s[j]=='1' add '22' / s[j]=='2' add '11'
        int i = 2,j=2;
        while(j<n){
            if(ans[i]=='2'){
                if(ans[j]=='2'){
                    ans += "11";
                    j+=2;
                }else{
                    ans += "22";
                    j+=2;
                }
            }else{
                if(ans[j]=='2'){
                    ans+="1";
                }else{
                    ans += "2";
                }
                j++;
            }
            i++;
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(ans[i]=='1'){
                cnt++;
            }
        }
        return cnt;
    }
};
