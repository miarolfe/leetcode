class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexMap;

        for (int index = 0; index < nums.size(); index++)
        {
            int difference = target - nums[index];
            if (indexMap.find(difference) != indexMap.end())
            {
                return {indexMap[difference], index};
            }
            indexMap[nums[index]] = index;
        }

        return {-1, -1};
    }
};