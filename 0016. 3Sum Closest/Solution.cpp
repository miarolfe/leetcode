class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());

        int closest;
        int closestDiff = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            int low = i + 1;
            int high = nums.size() - 1;

            int localTarget = target - nums[i];

            while (low < high)
            {
                int twoSum = nums[low] + nums[high];
                int threeSum = twoSum + nums[i];

                int diff = abs(target - threeSum);
                if (diff < closestDiff)
                {
                    closestDiff = diff;
                    closest = threeSum;
                }

                if (twoSum <= localTarget)
                {
                    low++;
                }
                else if (twoSum >= localTarget)
                {
                    high --;
                }

            }
        }

        return closest;
    }
};