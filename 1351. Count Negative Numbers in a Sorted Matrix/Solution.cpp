class Solution 
{
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int negativeCount = 0;

        for (int i = 0; i < m; i++)
        {
            int low = 0;
            int high = n;

            while (low < high)
            {
                int mid = (low + high) / 2;
                if (grid[i][mid] < 0)
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }

            negativeCount += n - low;
        }

        return negativeCount;
    }
};