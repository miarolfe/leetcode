class Solution 
{
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        if (triangle.size() == 1) return triangle[0][0];
        if (triangle.size() == 2) return triangle[0][0] + min(triangle[1][0], triangle[1][1]);

        int numRows = triangle.size();
        int dp[numRows][numRows];

        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < numRows; j++)
            {
                dp[i][j] = 0;
            }
        }

        dp[0][0] = triangle[0][0];
        dp[1][0] = triangle[1][0] + dp[0][0];
        dp[1][1] = triangle[1][1] + dp[0][0];

        for (int row = 2; row < numRows; row++)
        {
            for (int cell = 0; cell <= row; cell++)
            {
                if (cell == 0) dp[row][0] = triangle[row][0] + dp[row - 1][0];
                else if (cell == row) dp[row][cell] = triangle[row][row] + dp[row - 1][row - 1];
                else dp[row][cell] = triangle[row][cell] + min(dp[row - 1][cell - 1], dp[row - 1][cell]);
            }
        }

        int lowestPathSum = INT_MAX;
        for (int cell = 0; cell < numRows; cell++)
        {
            if (dp[numRows - 1][cell] < lowestPathSum) lowestPathSum = dp[numRows - 1][cell];
        }

        return lowestPathSum;
    }
};