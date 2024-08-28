class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int leftIndex = 0;
        int rightIndex = 0;
        int length = s.size();
        int maxLength = 0;
        unordered_map<char, int> freqMap;

        for (; rightIndex < length; rightIndex++)
        {
            // If char not in map or index less than left, it is new unique char
            if (freqMap.count(s[rightIndex]) == 0 || freqMap[s[rightIndex]] < leftIndex)
            {
                freqMap[s[rightIndex]] = rightIndex;
                maxLength = max(maxLength, rightIndex - leftIndex + 1);
            }
            else
            {
                leftIndex = freqMap[s[rightIndex]] + 1;
                freqMap[s[rightIndex]] = rightIndex;
            }
        }

        return maxLength;
    }
};