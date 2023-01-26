class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vector<int> t;
        int m = students.size(), n = students[0].size();
        for(int i=0; i<m; i++) t.push_back(i);
        int ans = 0;
        do{
            int cnt = 0;
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(students[t[i]][j] == mentors[i][j]) cnt++;
                }
            }
            ans = max(ans,cnt);
        }while(next_permutation(t.begin(),t.end()));
        return ans;
    }
    
};
