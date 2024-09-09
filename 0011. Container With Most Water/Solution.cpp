class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int low = 0;
        int high = height.size() - 1;
        int maxWater = 0;

        while (low < high)
        {
            maxWater = max(maxWater, min(height[low], height[high]) * (high - low));
            if (height[low] > height[high])
            {
                high--;
            }
            else
            {
                low++;
            } 
        }

        return maxWater;
    }
};