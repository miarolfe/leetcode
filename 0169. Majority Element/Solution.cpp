class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int currentBestCandidateCount = 0;
        int currentBestCandidate = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (currentBestCandidateCount == 0)
            {
                currentBestCandidate = nums[i];
            }

            if (nums[i] == currentBestCandidate) currentBestCandidateCount++;
            else currentBestCandidateCount--;
        }

        return currentBestCandidate;
    }
};