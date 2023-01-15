class Solution {
public:
int n, m;
int arr[202][202];
int dp[202][202];
int done[202][202];

// state:- dp[r][c] - minimum health require to reach n-1,m-1 from r,c;
// transition: as below;

int rec(int r, int c)
{

    if (r == n - 1 && c == m - 1)
    {

        int val = 1 - arr[r][c];
        int rem = 1;
        return max(rem, val);
    }

    if (done[r][c])
        return dp[r][c];

    int rt = 1e9, lf = 1e9;
    if (r < n - 1)
    {
        rt = rec(r + 1, c);
    }
    if (c < m - 1)
    {
        lf = rec(r, c + 1);
    }

    int ans = 1;
    ans = max(ans, min(rt, lf) - arr[r][c]);
    done[r][c] = 1;
    return dp[r][c] = ans;
}

int calculateMinimumHP(vector<vector<int>> &dungeon)
{
    n = dungeon.size();
    m = dungeon[0].size();

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            done[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = dungeon[i][j];
        }
    }

    return rec(0,0);
}
};
