class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> numsSet;
        for (int num : nums)
        {
            numsSet.insert(num);
        }

        int longest = 0;

        for (int num : numsSet)
        {
            if (numsSet.count(num - 1) == 0)
            {
                int x = num + 1;
                while (numsSet.count(x) > 0)
                {
                    x++;
                }

                longest = max(longest, x - num);
            }
        }

        return longest;
    }
};