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
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    DoublyLinkedListNode *node, *next, *prev;
    for (node = head; node != NULL; node = next) {
        prev = node;
        next = node->next;
        node->next = node->prev;
        node->prev = next;
    }

    return prev;
}
