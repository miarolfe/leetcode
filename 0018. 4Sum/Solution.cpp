class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> quadruplets;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                long long localTarget = (long long) target - (long long) nums[i] - (long long) nums[j];

                int low = j + 1;
                int high = nums.size() - 1;

                while (low < high)
                {
                    int twoSum = nums[low] + nums[high];

                    if (twoSum < localTarget)
                    {
                        low++;
                    }
                    else if (twoSum > localTarget)
                    {
                        high--;
                    }
                    else
                    {
                        vector<int> quadruplet = {nums[i], nums[j], nums[low], nums[high]};
                        quadruplets.push_back(quadruplet);
                        while (low < high && nums[low] == quadruplet[2]) low++;
                        while (low < high && nums[high] == quadruplet[3]) high--;
                    }
                }

                while (j + 1 < nums.size() && nums[j] == nums[j + 1]) j++;
            }

            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }

        return quadruplets;
    }
};