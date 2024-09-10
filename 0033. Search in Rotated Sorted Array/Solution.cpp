class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;

            // If left half is sorted
            if (nums[left] <= nums[mid])
            {   
                // Target is in left half
                if (nums[left] <= target && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
            else
            {   
                // Target is in right half
                if (nums[mid] < target && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }

        // Target not in array
        return -1;
    }
};