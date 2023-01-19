class Solution {
public:

    int convert(string s){
        int num = 0;
        reverse(s.begin(),s.end());
        int n = s.length();
        for(int i=0; i<n; i++){
            num += (s[i]-'0')*(1<<i);
        }
        return num;
    }

    bool hasAllCodes(string s, int k) {
       set<string> st;
       int n = s.length();
       for(int i=0; i<=n-k; i++){
           st.insert(s.substr(i,k));
       }
       
       int num = 1<<k;
       if(st.size()==num) return true;
       return false;

    }
};
