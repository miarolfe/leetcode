/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode;
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* first = head;
        ListNode* second = first->next;

        while (first && second)
        {
            first->next = second->next;
            second->next = first;
            prev->next = second;
            prev = first;
            first = first->next;
            if (first) second = first->next;
        }

        return dummy->next;
    }
};