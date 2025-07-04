// https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/problem?isFullScreen=true
 
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    if (llist != nullptr) {
        SinglyLinkedListNode* head = new SinglyLinkedListNode(data);
        head->next = llist;
        return head;
    } else {
        return new SinglyLinkedListNode(data);
    }
}
