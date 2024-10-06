class Solution 
{
public:
    int maxSum(vector<vector<int>>& grid) 
    {
        int maximumSum = 0;

        for (int i = 1; i < grid.size() - 1; i++) 
        {
            for (int j = 1; j < grid[i].size() - 1; j++)
            {
                int hourglassSum = 0;

                hourglassSum += grid[i - 1][j - 1];
                hourglassSum += grid[i - 1][j];
                hourglassSum += grid[i - 1][j + 1];
                hourglassSum += grid[i][j];
                hourglassSum += grid[i + 1][j - 1];
                hourglassSum += grid[i + 1][j];
                hourglassSum += grid[i + 1][j + 1];

                maximumSum = max(hourglassSum, maximumSum);
            }
        }

        return maximumSum;
    }
};