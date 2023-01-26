class Solution {
public:

    bool get(int n, int b){
        string res = "";
        while(n){
            int rem = n%b;
            res += to_string(rem);
            n/=b;
        }
        int m = res.length();
        bool f = true;
        for(int i=0; i<m/2; i++){
            if(res[i] != res[m-i-1]){
                f = false;
                break;
            }
        }
        return f;
    }


    bool isStrictlyPalindromic(int n) {
        bool f = true;
        for(int base = 2; base<=n-2; base++){
            if(!get(n,base)){
                f = false;
                break;
            }
        }
        return f;
    }
};
