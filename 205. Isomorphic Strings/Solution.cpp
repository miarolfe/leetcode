class Solution 
{
public:
    bool isIsomorphic(string s, string t) 
    {
        unordered_map<char, char> charMap;
        unordered_map<char, bool> charUsedMap;

        for (int i = 0; i < s.size(); i++)
        {
            // Is the char already mapped?
            if (charMap.count(s[i]) != 0)
            {
                if (charMap[s[i]] != t[i])
                {
                    return false;
                }
            }
            else // The char isn't mapped
            {
                // The char we want to map to has been used already
                if (charUsedMap[t[i]]) return false;

                charMap[s[i]] = t[i];
                charUsedMap[t[i]] = true;
            }
        }

        return true;
    }
};