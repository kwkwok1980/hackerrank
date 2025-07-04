//https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/problem?isFullScreen=true

void reversePrint(SinglyLinkedListNode* llist) {
    std::stack<SinglyLinkedListNode*> node_stack{};
    SinglyLinkedListNode* cursor = llist;
    while (cursor != nullptr) {
        node_stack.push(cursor);
        cursor = cursor->next;
    }
    while (!node_stack.empty()) {
        cursor = node_stack.top();
        node_stack.pop();
        std::cout << cursor->data << std::endl;
    }
}
