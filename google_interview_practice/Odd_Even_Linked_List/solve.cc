class Solution {
public:
  ListNode* oddEvenList(ListNode* head) {
		ListNode *oddHead, *odd;
		ListNode *evenHead, *even;
		oddHead = NULL;
		odd = NULL;
		evenHead = NULL;
		even = NULL;
		int i = 1;
		for (ListNode *node = head; node != NULL; node = node->next) {
    	if (i % 2 == 1) {
				if (oddHead == NULL) {
					oddHead = node;
				} else {
					odd->next = node;
				}
				odd = node;
			} else {
				if (evenHead == NULL) {
					evenHead = node;
				} else {
					even->next = node;
				}
				even = node;
			}
			++i;
		}
		if (odd) {
			odd->next = evenHead;
		}
		if (even) {
			even->next = NULL;
		}
		return oddHead;
	}
};



