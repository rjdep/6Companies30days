class Solution {
public:
    int maxUniqueSplit(string s) {
        int ans = 0;
        int n = s.length();
        for(int i=0; i<(1LL<<n); i++){
            if(__builtin_popcount(i)<ans) continue;
            set<string> st;
            int cnt = 0;
            int prev = -1;
            bool f = true;
            for(int j=0; j<n; j++){
                if(i&(1LL<<j)){
                    cnt++;
                    string t = s.substr(prev+1,j-prev);
                    if(st.find(t) == st.end()){
                        st.insert(t);
                        prev = j;
                    }else{
                        f = false;
                        break;
                    }
                }
            }
            cnt++;
            string t = s.substr(prev+1,n-prev-1);
            if(st.find(t) != st.end()) f = false;
            st.insert(s.substr(prev+1,n-prev-1)); // 6 - 4 + 1
            if(f){
                ans = max(ans,cnt);
            }
        }
        return ans-1;
    }
};
