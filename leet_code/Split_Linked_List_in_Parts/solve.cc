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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> ret;
        int size = 0;

        for (ListNode *node = root; node != NULL; node = node->next) {
            ++size;
        }

        if (size < k) {
            int i = 0;
            for (ListNode *node = root; node != NULL; ++i) {
                ListNode *nd = node;
                ret.push_back(nd);
                node = node->next;
                nd->next = NULL;
            }
            while (i < k) {
                ret.push_back(NULL);
                ++i;
            }
        } else {
            int more = size % k;
            int count = size / k;
            for (ListNode *node = root; node != NULL;) {
                ListNode* prev = node;

                ret.push_back(node);
                for (int i = 0; i < count; ++i) {
                    prev = node;
                    node = node->next;
                }

                if (more > 0) {
                    prev = node;
                    node = node->next;
                    --more;
                }
                prev->next = NULL;
            }
        }

        return ret;
    }
};
