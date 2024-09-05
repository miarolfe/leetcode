class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int uniqueElements = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            // Check nums[i] is not a duplicate
            if (nums[i] != nums[i - 1])
            {
                nums[uniqueElements] = nums[i];
                uniqueElements++;
            }
        }

        return uniqueElements;
    }
};