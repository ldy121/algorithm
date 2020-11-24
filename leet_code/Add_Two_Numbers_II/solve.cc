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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> sp1;
        stack<ListNode*> sp2;
        stack<ListNode*> answer;
        ListNode* ret;
        int carry = 0;

        for (ListNode* node = l1; node != NULL; node = node->next) {
            sp1.push(node);
        }

        for (ListNode* node = l2; node != NULL; node = node->next) {
            sp2.push(node);
        }

        while (!sp1.empty() || !sp2.empty()) {
            int val1, val2;
            if (!sp1.empty()) {
                val1 = sp1.top()->val;
                sp1.pop();
            } else {
                val1 = 0;
            }
            
            if (!sp2.empty()) {
                val2 = sp2.top()->val;
                sp2.pop();
            } else {
                val2 = 0;
            }
            int val = (val1 + val2 + carry);
            ListNode * node = new ListNode(val % 10);
            carry = val / 10;
            answer.push(node);
        }
        
        if (carry > 0) {
            answer.push(new ListNode(carry));
        }
   
        ret = answer.top();

        if (answer.size() > 1) {
            for (ListNode *node = answer.top(); !answer.empty(); answer.pop()) {
                node->next = answer.top();
                node = answer.top();
            }
        }
        return ret;
    }
};
