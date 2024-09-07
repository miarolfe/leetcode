class Solution 
{
public:
    bool isRowValid(const vector<char>& row)
    {
        set<char> seenDigits;
        for (char cell : row)
        {
            if (cell != '.' && seenDigits.count(cell) != 0) return false;
            seenDigits.insert(cell);
        }

        return true;
    }

    bool areColumnsValid(const vector<vector<char>>& board)
    {
        for (int column = 0; column < 9; column++)
        {
            set<char> seenDigits;
            for (int row = 0; row < 9; row++)
            {
                char cell = board[row][column];
                if (cell != '.' && seenDigits.count(cell) != 0) return false;
                seenDigits.insert(cell);
            }
        }

        return true;
    }

    bool isSubBoxValid(const vector<vector<char>>& board, int xStart, int yStart)
    {
        set<char> seenDigits;
        for (int i = xStart; i < xStart + 3; i++)
        {
            for (int j = yStart; j < yStart + 3; j++)
            {
                char cell = board[i][j];
                if (cell != '.' && seenDigits.count(cell) != 0) return false;
                seenDigits.insert(cell);
            }
        }

        return true;
    }

    bool areSubBoxesValid(const vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                if (!isSubBoxValid(board, i, j)) return false;
            }
        }

        return true;
    }  

    bool isValidSudoku(vector<vector<char>>& board) 
    {
        for (int i = 0; i < 9; i++)
        {
            if (!isRowValid(board[i])) return false;
        }

        if (!areColumnsValid(board)) return false;
        if (!areSubBoxesValid(board)) return false;

        return true;
    }
};