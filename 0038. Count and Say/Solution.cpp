class Solution {
public:
    string runLengthEncoding(string original)
    {
        if (original.size() == 1)
        {
            string encoded;
            encoded += '1';
            encoded += original[0];
            return encoded;
        }

        vector<pair<int, char>> x;
        int currentRunLength = 1;
        char currentChar = original[0];

        for (int i = 1; i < original.size(); i++)
        {
            char c = original[i];
            if (c == currentChar)
            {
                currentRunLength++;
            }
            else
            {
                x.push_back({currentRunLength, currentChar});
                currentRunLength = 1;
                currentChar = c;
            }
        }

        // Don't forget the last streak
        x.push_back({currentRunLength, currentChar});

        string encoded;
        for (const auto& pair : x)
        {
            encoded += to_string(pair.first) + pair.second;
        }

        return encoded;
    }

    string countAndSay(int n) 
    {
        int i = 1;
        string rle = "1";
        while (i < n)
        {
            rle = runLengthEncoding(rle);
            cout << rle << endl;
            i++;
        }

        return rle;
    }
};