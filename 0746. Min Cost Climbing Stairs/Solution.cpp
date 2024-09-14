class Solution 
{
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        // At each point we only need to consider whether climbing one or two steps is cheaper
        for (int i = 2; i < cost.size(); i++)
        {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }

        return min(cost[cost.size() - 1], cost[cost.size() - 2]);
    }
};