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
    vector<int> nextLargerNodes(ListNode* head) {
    	vector<int> ret;
    	stack<int> sp;
        for (ListNode* node = head; node != NULL; node = node->next) {
            while (!sp.empty()) {
                if (ret[sp.top()] < node->val) {
                    ret[sp.top()] = node->val;
                    sp.pop();
                } else {
                    break;
                }
            }
            sp.push(ret.size());
            ret.push_back(node->val);
        }
        while (!sp.empty()) {
            ret[sp.top()] = 0;
            sp.pop();
        }
        return ret;
    }
};

