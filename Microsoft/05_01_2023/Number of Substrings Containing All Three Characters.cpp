class Solution {
public:
    int numberOfSubstrings(string s) {
        int arr[3]={0,0,0};
        int n = s.length();
        int j = 0,cnt = 0;
        for(int i=0; i<n; i++){
            arr[s[i]-'a']++;
            while(arr[0] && arr[1] && arr[2]){
                cnt+=(n-i);
                arr[s[j]-'a']--;
                j++;
            }

        }
        return cnt;

    }
};
