/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* lResult = new ListNode(0);
            ListNode* pl1 = l1;
            ListNode* pl2 = l2;
            ListNode* plResult = lResult;
            int addVal = 0;
            while (pl1 != NULL || pl2 != NULL) {
                plResult->val = addVal;
                plResult->val += (pl1 == NULL ? 0 : pl1->val);
                plResult->val += (pl2 == NULL ? 0 : pl2->val);
                addVal = plResult->val / 10;
                plResult->val = plResult->val % 10;
                pl1 = (pl1 == NULL ? NULL : pl1->next);
                pl2 = (pl2 == NULL ? NULL : pl2->next);
                if (pl1 != NULL || pl2 != NULL) {
                    plResult->next = new ListNode(0);
                    plResult = plResult->next;
                }
            }
            if (addVal != 0)
                plResult->next = new ListNode(addVal);
            return lResult;
        }
};
