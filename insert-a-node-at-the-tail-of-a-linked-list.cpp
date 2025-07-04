 // https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem?isFullScreen=true
 
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    if (head != nullptr) {
        SinglyLinkedListNode* cursor = head;
        while (cursor->next != nullptr) {
            cursor = cursor->next;
        }
        cursor->next = new SinglyLinkedListNode(data);
        return head;    
    } else {
        return new SinglyLinkedListNode(data);
    }    
}
