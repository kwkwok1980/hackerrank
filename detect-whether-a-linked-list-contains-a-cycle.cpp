 // https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/problem?isFullScreen=true
 
bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* cursor1 = head;
    SinglyLinkedListNode* cursor2 = head;
    while (true) {
        if (cursor1->next != nullptr) {
            cursor1 = cursor1->next;
        } else {
            return false;
        }
        if (cursor2->next != nullptr && cursor2->next->next != nullptr) {
            cursor2 = cursor2->next->next;
        } else {
            return false;
        }
        if (cursor1 == cursor2) {
            return true;
        }        
    }
}
