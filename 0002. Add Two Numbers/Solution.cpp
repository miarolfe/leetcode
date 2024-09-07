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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* resultDummy = new ListNode;
        ListNode* currentResultNode = resultDummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry)
        {
            int total = 0;
            
            if (l1) 
            {
                total += l1->val;
                l1 = l1->next;

            }
            if (l2)
            { 
                total += l2->val;
                l2 = l2->next;
            }
            
            total += carry;

            // Max possible value is 18 (9 + 9) 
            // So if we divide total by 10 that will either be a 0 (under 10) or a 1 (over 10)
            carry = total / 10;

            ListNode* extraNode = new ListNode(total % 10);
            currentResultNode->next = extraNode;
            currentResultNode = currentResultNode->next;
        }

        return resultDummy->next;
    }
};