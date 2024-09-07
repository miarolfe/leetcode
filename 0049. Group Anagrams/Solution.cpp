class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> grxoups;

        for (int i = 0; i < strs.size(); i++)
        {
            string sortedStr = strs[i];
            sort(sortedStr.begin(), sortedStr.end());
            groups[sortedStr].push_back(strs[i]);
        }

        vector<vector<string>> anagramGroups;
        
        for (const auto& group : groups)
        {
            anagramGroups.push_back(group.second);
        }
        
        return anagramGroups;
    }
};