class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;

        // Fix the first number to simplify the problem
        for (int i = 0; i < nums.size(); i++)
        {
            int target = -nums[i]; // Everything needs to sum to zero

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                int twoSum = nums[left] + nums[right];

                if (twoSum < target) left++;
                else if (twoSum > target) right--;
                else
                {
                    vector<int> triplet = {nums[i], nums[left], nums[right]};
                    triplets.push_back(triplet);

                    // Skip duplicates for second and third nums
                    while (left < right && nums[left] == triplet[1]) left++;
                    while (left < right && nums[right] == triplet[2]) right--;
                }
            }

            // Skip duplicates for first num
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }


        return triplets;
    }
};