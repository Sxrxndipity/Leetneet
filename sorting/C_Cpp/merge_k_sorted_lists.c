#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

struct ListNode* merge(struct ListNode* list1, struct ListNode* list2);

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {

    int n = listsSize;
    if (!lists || n == 0) {
        return NULL;
    }

    while (n > 1) {
        ListNode** temp = (ListNode**)malloc(sizeof(ListNode*) * (n / 2 + n % 2));
        int k = 0;
        for (int i = 0; i < n; i += 2) {
            ListNode* l1 = lists[i];
            ListNode* l2 = (i+1 < n) ? lists[i+1] : NULL;
            temp[k] = merge(l1,l2);
            k++;
        }
        lists = temp;
    }
    return lists[0];
}

struct ListNode* merge(struct ListNode* list1, struct ListNode* list2) {

    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    struct ListNode* tail = dummy;

    while(list1 && list2) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        }
        else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    if (list1) {
        tail->next = list1;
    }
    else if (list2) {
        tail->next = list2;
    }

    return dummy->next;
}

