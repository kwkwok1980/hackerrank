// https://www.hackerrank.com/challenges/reverse-a-linked-list/problem?isFullScreen=true

SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    if (llist != nullptr) {
        SinglyLinkedListNode* previous = nullptr;
        SinglyLinkedListNode* cursor = llist;
        SinglyLinkedListNode* next = nullptr;
        while (true) {
            next = cursor->next;
            cursor->next = previous;
            if (next != nullptr) {
                previous = cursor;
                cursor = next;                
            } else {
                break;
            }
        }
        return cursor;
    } else {
        return nullptr;
    }
    
    
}
