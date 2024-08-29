class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        int sCharFreqMap[26];
        int tCharFreqMap[26];
        for (int i = 0; i < s.length(); i++)
        {
            sCharFreqMap[s[i] - 'a']++;
            tCharFreqMap[t[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (sCharFreqMap[i] != tCharFreqMap[i]) return false;
        }

        return true;
    }
};