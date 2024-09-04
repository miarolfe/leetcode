class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int needleSize = needle.size();
        if (needleSize > haystack.size()) return -1;

        int i = 0;

        for (int i = 0; i <= haystack.size() - needleSize; i++)
        {
            if (haystack[i] == needle[0])
            {
                if (haystack.substr(i, needleSize) == needle) return i;
            }
        }

        return -1;    
    }
};