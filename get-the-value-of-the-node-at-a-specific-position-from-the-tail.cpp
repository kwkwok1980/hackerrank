// https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem?isFullScreen=true

int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    std::stack<SinglyLinkedListNode*> node_stack{};
    SinglyLinkedListNode* cursor = llist;
    while (cursor != nullptr) {
        node_stack.push(cursor);
        cursor = cursor->next;
    }
    for (int i=0; i<=positionFromTail; ++i) {
        cursor = node_stack.top();
        node_stack.pop();
    }
    return cursor->data;
}
