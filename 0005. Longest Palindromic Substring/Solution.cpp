class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        if (s.size() <= 1) return s;

        int maxLength = 0;
        string longestPalindrome = "";

        for (int i = 0; i < s.size(); i++)
        {
            string odd = expand(s, i, i);
            if (odd.size() > maxLength)
            {
                longestPalindrome = odd;
                maxLength = odd.size();
            }

            string even = expand(s, i, i + 1);
            if (even.size() > maxLength)
            {
                longestPalindrome = even;
                maxLength = even.size();
            }

        }

        return longestPalindrome;
    }

    string expand(string str, int left, int right)
    {
        while (left >= 0 && right < str.size() && str[left] == str[right])
        {
            left--;
            right++;
        }

        return str.substr(left + 1, right - left - 1);;
    }
};