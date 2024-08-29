/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    bool hasCycle(ListNode* head) 
    {
        unordered_set<ListNode*> seenNodes;

        while (head)
        {
            if (seenNodes.count(head) > 0) return true;
            seenNodes.insert(head);
            head = head->next;
        }

        return false;
    }
};