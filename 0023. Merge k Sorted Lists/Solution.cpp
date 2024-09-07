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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> values;

        if (lists.empty()) return nullptr;

        for (ListNode* list : lists)
        {
            ListNode* currentNode = list;
            while (currentNode)
            {
                values.push(currentNode->val);
                currentNode = currentNode->next;
            }
        }

        if (values.empty()) return nullptr;


        ListNode* root = new ListNode;
        ListNode* temp = root;
        while (!values.empty())
        {
            temp->val = values.top();
            values.pop();

            if (!values.empty())
            {
                temp->next = new ListNode;
                temp = temp->next;
            }
        }

        return root;
    }

};