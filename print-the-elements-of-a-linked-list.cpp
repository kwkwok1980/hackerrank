// https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/problem?isFullScreen=true
 
void printLinkedList(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* cursor = head;
    while (cursor != nullptr) {
        std::cout << cursor->data << std::endl;
        cursor = cursor->next;
    }
}
