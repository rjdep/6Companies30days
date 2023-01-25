class Solution {
public:

    

    bool check(string s){
        if(s.length()>3 || s.length()==0) return false;
        if(s[0]=='0' && s.length()>1) return false;
        int num = 0;
        for(int i=0; i<s.length(); i++){
            num = num*10 + (s[i]-'0');
        }
        if(num>=0 && num<=255) return true;
        return false;
    }
    /*
    set<string> ans;
    void rec(int idx, string res, string &s, int n, int cnt){
        // cout<<idx<<" "<<res<<" "<<cnt<<endl;
        if(idx==n){
            vector<string> v;
            string rem = "";
            for(auto x: res){
                if(x=='.'){
                    v.push_back(rem);
                    rem="";
                }else{
                    rem += x;
                }
            }
            v.push_back(rem);
            if(v.size() != 4) return;
            // cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<endl;
            bool f = true;
            for(auto x: v){
                if(!check(x)){
                    f = false;
                    break;
                }
            }
            // cout<<f<<endl;
            if(f) ans.insert(res);   
            return;         
        }
        
        res += s[idx];
        if(cnt<3){
            res += ".";
            rec(idx+1,res,s,n,cnt+1);
            res.pop_back();
        }
        rec(idx+1,res,s,n,cnt);
        
    }

    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        vector<string> temp;
        if(n>3*4) return temp;
        string t = "";
        rec(0,t,s,n,0);
        for(auto x: ans){
            temp.push_back(x);
        }
        return temp;
    }

    */

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int n = s.length();
        if(n>12) return ans;
        for(int i=1; i<=3; i++){
            for(int j=1; j<=3; j++){
                for(int k=1; k<=3; k++){
                    if(i+j+k>=n) continue;
                    string a = s.substr(0,i);
                    string b = s.substr(i,j);
                    string c = s.substr(j+i,k);
                    string d = s.substr(k+i+j,n-k);
                    // cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                    if(check(a) && check(b) && check(c) && check(d)){
                        ans.push_back(a+"."+b+"."+c+"."+d);
                    }
                }
            }
        }
        return ans;
    }
};
