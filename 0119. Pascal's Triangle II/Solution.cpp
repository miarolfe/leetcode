class Solution 
{
public:
    vector<int> getRow(int rowIndex) 
    {
        if (rowIndex == 0) return {1};
        if (rowIndex == 1) return {1, 1};

        vector<vector<int>> triangle;
        triangle.push_back({1});
        triangle.push_back({1, 1});

        for (int row = 2; row <= rowIndex; row++)
        {
            vector<int> previousRow = triangle[row - 1];
            vector<int> currentRow;
        
            currentRow.push_back(1);
            for (int i = 1; i < row; i++)
            {
                currentRow.push_back(previousRow[i - 1] + previousRow[i]);
            }
            currentRow.push_back(1);

            triangle.push_back(currentRow);
        }
    
        return triangle[rowIndex];
    }
};