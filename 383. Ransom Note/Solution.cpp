class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        const int NUM_LOWER_CASE_ENGLISH_LETTERS = 26;
        const int ASCII_OFFSET = 'a';

        int ransomNoteFreqMap[NUM_LOWER_CASE_ENGLISH_LETTERS];
        int magazineFreqMap[NUM_LOWER_CASE_ENGLISH_LETTERS];

        for (char c : ransomNote)
        {
            ransomNoteFreqMap[c - ASCII_OFFSET]++;
        }

        for (char c : magazine)
        {
            magazineFreqMap[c - ASCII_OFFSET]++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (ransomNoteFreqMap[i] > magazineFreqMap[i]) return false;
        }

        return true;
    }
};