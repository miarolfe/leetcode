class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        string xStr = to_string(x);

        int low = 0;
        int high = xStr.size() - 1;

        while (low < high)
        {
            if (xStr[low] != xStr[high]) return false;
            low++;
            high--;
        }

        return true;
    }
};