class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        int dp[m][n];

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0) dp[i][j] = 1;
                else
                {
                    int up;
                    int right;

                    i > 0 ? up = dp[i - 1][j] : up = 0;
                    j > 0 ? right = dp[i][j - 1] : right = 0;
                    dp[i][j] = up + right;
                }
                
            }
        }

        return dp[m-1][n-1]; // Get unique paths at botoom right
    }
};