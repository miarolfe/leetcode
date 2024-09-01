class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int nums1Size = nums1.size();
        int nums2Size = nums2.size();

        if (nums1Size > nums2Size) return findMedianSortedArrays(nums2, nums1);

        int totalSize = nums1Size + nums2Size;

        int left = (nums1Size + nums2Size + 1) / 2;
        int low = 0;
        int high = nums1Size;

        while (low <= high)
        {
            int nums1Mid = (low + high) / 2;
            int nums1Left = INT_MIN;
            int nums1Right = INT_MAX;
            int nums2Mid = left - nums1Mid;
            int nums2Left = INT_MIN;
            int nums2Right = INT_MAX;

            if (nums1Mid - 1 >= 0) nums1Left = nums1[nums1Mid - 1];
            if (nums1Mid < nums1Size) nums1Right = nums1[nums1Mid];
            if (nums2Mid - 1 >= 0) nums2Left = nums2[nums2Mid - 1];
            if (nums2Mid < nums2Size) nums2Right = nums2[nums2Mid];

            if (nums1Left <= nums2Right && nums2Left <= nums1Right)
            {
                if (totalSize % 2 == 1)
                {
                    return max(nums1Left, nums2Left);
                }
                else
                {
                    return (double) (max(nums1Left, nums2Left) + min(nums1Right, nums2Right)) / 2.0;
                }
            }
            else if (nums1Left > nums2Right)
            {
                high = nums1Mid - 1;
            }
            else
            {
                low = nums1Mid + 1;
            }
        }

        return -1.0f;
    }
};