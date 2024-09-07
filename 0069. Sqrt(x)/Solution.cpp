class Solution 
{
public:
    int mySqrt(int x) 
    {
        if (x == 0 || x == 1) return x;
        if (x >= INT_MAX) return 46340;

        cout << INT_MAX << endl;

        int low = 0;
        int high = x;
        int rootCandidate = 1; 

        while (low <= high)
        {
            float root = (low + high) / 2;
            if (root * root == x)
            {
                rootCandidate = root;
                break;
            }
            else if (root < x/root)
            {
                rootCandidate = root;
                low = (int) root + 1;
            }
            else
            {
                high = (int) root - 1;
            }  
        }

        if (rootCandidate * rootCandidate > x) return (int) rootCandidate - 1;
        else return (int) rootCandidate;
    }
};