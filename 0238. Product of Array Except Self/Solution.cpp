class Solution 
{
public:

    // Time: O(n)

    // Space: O(n)
    // This could be reduced to O(1) with DP tricks
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> answer(nums.size(), 0);
        vector<int> prefixProduct(nums.size(), 1);
        vector<int> suffixProduct(nums.size(), 1);

        int i = 1;
        int j = nums.size() - 2;

        prefixProduct[0] = nums[0];
        suffixProduct[nums.size() - 1] = nums[nums.size() - 1];
        for (; i < nums.size() && j >= 0; i++, j--)
        {
            prefixProduct[i] = prefixProduct[i - 1] * nums[i];
            suffixProduct[j] = suffixProduct[j + 1] * nums[j];
        }

        answer[0] = suffixProduct[1];
        for (int i = 1; i < answer.size() - 1; i++)
        {
            answer[i] = prefixProduct[i - 1] * suffixProduct[i + 1];
        }
        answer[answer.size() - 1] = prefixProduct[answer.size() - 2];

        return answer;
    }
};