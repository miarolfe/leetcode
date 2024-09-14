class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int maxJumpFromI = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (maxJumpFromI < 0) return false;
            else if (nums[i] > maxJumpFromI) maxJumpFromI = nums[i];
            maxJumpFromI--;
        }

        return true;   
    }
};