/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode * node, * next;
    for (node = head1; node != NULL; node = next) {
        next = node->next;
        node->next = NULL;
    }
    for (node = head2; node->next != NULL; node = node->next);
    return node->data;
}
