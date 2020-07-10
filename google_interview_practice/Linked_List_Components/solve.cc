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
    int numComponents(ListNode* head, vector<int>& G) {
	unordered_map<int, bool> hash;
	int ret = 0;

	for (int i = 0; i < G.size(); ++i) {
		hash[G[i]] = true;
	}
	for (ListNode *node = head, *prev = NULL; node != NULL; node = node->next) {
		if (hash.find(node->val) != hash.end()) {
			if (prev == NULL || hash.find(prev->val) == hash.end()) {
				++ret;
			}
		}
		prev = node;
	}
	return ret;
    }
};

