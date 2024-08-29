class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seenNums;
        
        for (int num : nums)
        {
            if (seenNums.count(num) > 0) return true;
            seenNums.insert(num);
        }

        return false;
    }
};