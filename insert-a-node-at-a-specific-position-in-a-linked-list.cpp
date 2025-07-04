// https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem?isFullScreen=true

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    if (llist != nullptr) {
        SinglyLinkedListNode* cursor = llist;
        for (int i=0; i<position; ++i) {
            cursor = cursor->next;
        }
        SinglyLinkedListNode* node = new SinglyLinkedListNode(cursor->data);
        node->next = cursor->next;
        cursor->data = data;
        cursor->next = node;
        return llist;
    } else {
        return new SinglyLinkedListNode(data);
    }
}
