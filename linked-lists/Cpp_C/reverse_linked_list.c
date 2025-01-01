#include <string.h>

  struct ListNode {
      int val;
      struct ListNode *next;
  };
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* nxt = NULL;
    while(head) {
        nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }
    head = prev;
    return head;
}
