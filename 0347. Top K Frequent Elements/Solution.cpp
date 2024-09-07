class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> freqMap;
        for (int num : nums)
        {
            freqMap[num]++;
        }

        // We have n+1 buckets to account for the case of 0 frequency
        vector<vector<int>> freqBuckets(nums.size() + 1);
        for (auto pair : freqMap)
        {
            // Put element [pair.first] into bucket for elements freq [pair.second]
            freqBuckets[pair.second].push_back(pair.first);
        }

        vector<int> kFrequent;
        for (int i = freqBuckets.size() - 1; i >= 0; i--)
        {
            for (int element : freqBuckets[i])
            {
                kFrequent.push_back(element);
                if (kFrequent.size() == k) return kFrequent;
            }
        }

        return kFrequent;
    }
};