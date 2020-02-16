/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode * nd = new SinglyLinkedListNode(data);
    SinglyLinkedListNode * prev = NULL, * node = head;
    for (int i = 0; i < position; ++i) {
        prev = node;
        node = node->next;
    }

    nd->next = node;
    if (prev != NULL) {
        prev->next = nd;
        return head;
    } else {
        return nd;
    }
}
