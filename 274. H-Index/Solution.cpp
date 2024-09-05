class Solution 
{
public:
    int hIndex(vector<int>& citations) 
    {
        if (citations.size() == 0) return 0;

        vector<int> x(citations.size() + 1, 0);

        for (int i = 0; i < citations.size(); i++)
        {
            if (citations[i] >= citations.size()) 
            {
                x[citations.size()]++;
            } 
            else 
            {
                x[citations[i]]++;
            }
        }

        int papersWithICitations = 0;
        for (int i = citations.size(); i >= 0; i--)
        {
            papersWithICitations += x[i];
            if (papersWithICitations >= i) 
            {
                return i;
            }
        }

        return 0;
    }
};