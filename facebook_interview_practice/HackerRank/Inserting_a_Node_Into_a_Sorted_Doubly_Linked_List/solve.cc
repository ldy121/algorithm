/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode *prev, *node;
    DoublyLinkedListNode * nd = new DoublyLinkedListNode(data);

    for (node = head, prev = NULL; (node != NULL) && (node->data < data); node = node->next) prev = node;

    nd->prev = prev;
    nd->next = node;

    if (node != NULL) {
        node->prev = nd;
    }

    if (prev != NULL) {
        prev->next = nd;
        return head;
    } else {
        return nd;
    }
}
