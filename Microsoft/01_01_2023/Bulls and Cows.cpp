class Solution {
public:
    string getHint(string s, string g) {
        int cnt = 0;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i]==g[i]) cnt++;
        }
        vector<int> arr(10,0);
        for(int i=0; i<n; i++){
            if(s[i]==g[i]) continue;
            arr[s[i]-'0']++;
        }
        int cnt2 = 0;
        for(int i=0; i<n; i++){
            if(s[i]==g[i]) continue;
            if(arr[g[i]-'0']>0){
                cnt2++;
                arr[g[i]-'0']--;
            }
        }
        string ans = "";
        ans += to_string(cnt);
        ans += "A";
        ans += to_string(cnt2);
        ans += "B";
        return ans;
    }
};
