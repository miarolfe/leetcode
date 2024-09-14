class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        k %= nums.size();
        vector<int> rotatedSection = {nums.begin() + (nums.size() - k), nums.end()};
        rotatedSection.insert(rotatedSection.end(), nums.begin(), nums.end() - k);
        nums = rotatedSection;
    }
};