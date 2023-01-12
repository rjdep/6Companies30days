class Solution {
public:
    string fractionToDecimal(int n, int d) {

        bool f = false;
        if(1LL*n*d<0){
            f = true;
        }
        n = (long long)abs(n);
        d = abs(d);
        int gd = __gcd(n,d);
        n/=gd;
        d/=gd;
        long long dr = d;
        long long rem = n%dr;
        // cout<<rem<<endl;
        long long whole = n/dr;
        map<int,int> mp;
        string res = "";
        while(rem && mp.find(rem)==mp.end()){
            mp[rem]=res.length();
            rem *= 10;
            int x = rem/dr;
            cout<<x<<endl;
            res += to_string(abs(x));
            rem %= dr;
        }
        cout<<res<<" "<<mp[rem]<<endl;
        if(rem==0 && res.size()==0){
            string ans = to_string(abs(whole));
            cout<<ans<<endl;
            if(f) ans = "-"+ans;
        cout<<ans<<endl;
            return ans;
        }
        string frac = ".";
        if(rem==0){
            frac += res;
        }else{
            // cout<<frac<<endl;
            frac += res.substr(0,mp[rem]);
            frac += "(";
            frac += res.substr(mp[rem]);
            frac += ")";
            // cout<<frac<<endl;
        }
        // if(f) whole = whole*-1;
        string wh = to_string(abs(whole));
        // cout<<wh<<endl;
        // cout<<frac<<endl;
        string ans = wh + frac;
        // string ans = to_string(whole) + frac;
        if(f) ans = "-"+ans;
        return ans;
    }
};
