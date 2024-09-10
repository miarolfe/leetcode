class Solution 
{
private:
    const string digitToLetterMap[8] = 
    {
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

public:
    void solve(vector<string>& combinations, string digits, string base, int index)
    {
        // We have successfully explored all combinations
        if (index >= digits.size())
        {
            combinations.push_back(base);
        }
        else
        {
            int digitMapIndex = digits[index] - '0' - 2;
            string mapping = digitToLetterMap[digitMapIndex];

            for (int i = 0; i < mapping.length(); i++)
            {
                base.push_back(mapping[i]);
                solve(combinations, digits, base, index + 1);
                base.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) 
    {
        vector<string> combinations;
        if (digits.size() == 0) return combinations;

        string base = "";
        int index = 0;
        solve(combinations, digits, base, index);

        return combinations;
    }
};