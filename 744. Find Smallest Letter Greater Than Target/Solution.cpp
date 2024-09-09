class Solution 
{
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        int low = 0;
        int high = letters.size() - 1;

        if (letters[0] > target || target >= letters[letters.size() - 1]) return letters[0];

        char letter;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (letters[mid] > target)
            {
                high = mid - 1;
                letter = letters[mid];
            }
            else
            {
                low = mid + 1;
            }
        }

        return letter;
    }
};