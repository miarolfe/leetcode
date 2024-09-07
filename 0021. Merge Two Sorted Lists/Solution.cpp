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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* dummy = new ListNode;
        ListNode* current = dummy;

        if (!list1) return list2;
        if (!list2) return list1;

        while (list1 || list2)
        {
            if (list1 && list2) 
            {
                if (list1->val < list2->val)
                {
                    current->next = list1;
                    current = current->next;
                    list1 = list1->next;
                }
                else if (list1->val > list2->val)
                {
                    current->next = list2;
                    current = current->next;
                    list2 = list2->next;
                }
                else
                {
                    current->next = list1;
                    current = current->next;
                    list1 = list1->next;
                }
            }
            else if (list1)
            {
                current->next = list1;
                current = current->next;
                list1 = list1->next;
            }
            else if (list2)
            {
                current->next = list2;
                current = current->next;
                list2 = list2->next;
            }
        }

        return dummy->next;
    }
};