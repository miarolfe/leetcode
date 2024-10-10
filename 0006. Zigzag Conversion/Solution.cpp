class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        if (numRows == 1 || numRows >= s.size()) return s;

        string converted;

        if (numRows == 2)
        {
            for (int i = 0; i < s.size(); i += 2) converted.push_back(s[i]);
            for (int i = 1; i < s.size(); i += 2) converted.push_back(s[i]);
        }
        else
        {
            vector<string> rows(numRows);

            int i = 0;
            int direction = 1;

            for (char c : s)
            {
                rows[i].push_back(c);

                // We have hit the top row, turn around
                if (i == 0) 
                {
                    direction = 1;
                }

                // We have hit the bottom row, turn around
                else if (i == numRows - 1)
                {
                    direction = -1;
                }

                i += direction;
            }

            for (const string& row : rows)
            {
                converted += row; 
            }
        }

        return converted;
    }
};