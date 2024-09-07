class Solution 
{
public:
    int lengthOfLastWord(string s) 
    {
        int wordLength = 0;
        int x = s.size() - 1;

        while (x >= 0 && s[x] == ' ') x--;

        while (x >= 0 && s[x] != ' ') 
        {
            wordLength++;
            x--;
        }

        return wordLength;
    }
};