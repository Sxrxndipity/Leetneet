#include <stdbool.h>
#include <stdlib.h>
typedef struct node {
    int val;
    struct node* next;
} node;


typedef struct {
    node* head;
    node* curr;
    int size;
} MyStack;

node* nodeCreate(int val) {
    node* Node = (node*)malloc(sizeof(node));
    Node->next = NULL;
    Node->val = val;
    return Node;
}

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->head = NULL;
    stack->curr = NULL;
    stack->size = 0;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    node* entry = nodeCreate(x);
    if (obj->size == 0) {
        obj->head = entry;
        obj->curr = entry;
        obj->size ++;
    }
    else {
        obj->curr->next = entry;
        obj->curr = obj->curr->next;
        obj->size++;
    }
}

int myStackPop(MyStack* obj) {
    node* curs = obj->head;
    while (curs->next != obj->curr && obj->size > 0) {
        curs = curs->next;
    }
    int val = obj->curr->val;
    obj->curr = curs;
    obj->curr->next = NULL;
    obj->size--;
    return val;
}

int myStackTop(MyStack* obj) {
    return obj->curr->val;
}

bool myStackEmpty(MyStack* obj) {
    if (obj->size > 0) {
        return false;
    }
    else {
        return true;
    }
}

void myStackFree(MyStack* obj) {
    free(obj);
}
