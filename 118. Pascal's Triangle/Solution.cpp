class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        if (numRows == 1) return {{1}};
        if (numRows == 2) return {{1}, {1, 1}};
        vector<vector<int>> rows;
        rows.push_back({1});
        rows.push_back({1, 1});

        for (int rowNum = 3; rowNum <= numRows; rowNum++)
        {
            vector<int> previousRow = rows[rowNum - 2];
            vector<int> row;
            row.push_back(1);
            for (int rowIndex = 1; rowIndex < rowNum - 1; rowIndex++)
            {
                row.push_back(previousRow[rowIndex - 1] + previousRow[rowIndex]);
            }
            row.push_back(1);

            rows.push_back(row);
        }

        return rows;
    }
};