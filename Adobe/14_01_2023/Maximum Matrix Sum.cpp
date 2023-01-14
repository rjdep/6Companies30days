class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int n = matrix.size();
        int cnt = 0;
        int mn = 1e9;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ans += abs(matrix[i][j]);
                if(matrix[i][j]<0) cnt++;
                mn = min(mn,abs(matrix[i][j]));
            }
        }
        if(cnt%2){
            ans -= 2*mn;
        }
        return ans;
    }
};
