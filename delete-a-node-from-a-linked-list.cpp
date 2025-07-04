// https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem?isFullScreen=true

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    if (position != 0) {
        SinglyLinkedListNode* previous = nullptr;
        SinglyLinkedListNode* cursor = llist;
        for (int i=0; i<position; ++i) {
            previous = cursor;
            cursor = cursor->next;
        }
        previous->next = cursor->next;
        return llist;
    } else {
        return llist->next;
    }
}
