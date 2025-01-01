#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode ;

ListNode* reverseList(ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    ListNode* newHead=  head;
    if (head->next) {
        newHead = reverseList(head->next);
        head->next->next = head;
    }
    head->next = NULL;
    return newHead;
}
