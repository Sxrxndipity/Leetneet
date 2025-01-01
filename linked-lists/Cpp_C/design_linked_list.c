#include<stdlib.h>

typedef struct node {
    int val;
    struct node* next;
    struct node* prev;
} node;


typedef struct {
    node* right;
    node* left;
} MyLinkedList;

node* createNode(int val) {
    node* nd = (node*)malloc(sizeof(node));
    nd->val = val;
    nd->next = NULL;
    nd->prev = NULL;
    return nd;
}

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->right = createNode(0);
    obj->left = createNode(0);
    obj->right->prev = obj->left;
    obj->left->next = obj->right;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    node* cur = obj->left->next;
    while (cur && index > 0) {
        cur = cur->next;
        index--;
    }
    if (cur && cur != obj->right && index == 0) {
        return cur->val;
    }
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    node* Node = createNode(val);
    node* pre = obj->left;
    node* nxt = obj->left->next;

    pre->next = Node;
    Node->prev = pre;
    Node->next = nxt;
    nxt->prev = Node;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    node* Node = createNode(val);
    node* pre = obj->right->prev;
    node* nxt = obj->right;

    pre->next = Node;
    Node->prev = pre;
    Node->next = nxt;
    nxt->prev = Node;

}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    node* cur = obj->left->next;
    while (cur && index > 0) {
        cur = cur->next;
        index--;
    }
    if (cur && cur != obj->right->next && index == 0) {
        node* Node = createNode(val);
        node* pre = cur->prev;
        node* nxt = cur;

        pre->next = Node;
        Node->prev = pre;
        Node->next = nxt;
        nxt->prev = Node;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    node* cur = obj->left->next;
    while(cur && index > 0) {
        cur = cur->next;
        index--;
    }
    if (cur && cur != obj->right && index == 0){
        node* pre = cur->prev;
        node* nxt = cur->next;

        pre->next = nxt;
        nxt->prev = pre;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    free(obj->right);
    free(obj->left);
    free(obj);
}
