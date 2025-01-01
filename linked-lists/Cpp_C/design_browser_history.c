#include <stdlib.h>

typedef struct node {
    char* url;
    struct node* next;
    struct node* prev;
} node;

typedef struct {
    node* head;
    node* curr;
} BrowserHistory;

node* nodeCreate(char* string) {
    node* Node = (node*)malloc(sizeof(node));
    Node->url = string;
    Node->next = NULL;
    Node->prev = NULL;
    return Node;
}

BrowserHistory* browserHistoryCreate(char* homepage) {
    BrowserHistory* tab = (BrowserHistory*)malloc(sizeof(BrowserHistory));
    node* hpage = nodeCreate(homepage);
    tab->head = hpage;
    tab->curr = hpage;
    return tab;
}


void browserHistoryVisit(BrowserHistory* obj, char* url) {
    node* visit = nodeCreate(url);
    node* pre = obj->curr;
    pre->next = visit;
    visit->prev = pre;
    visit->next = NULL;
    obj->curr = visit;
}

char* browserHistoryBack(BrowserHistory* obj, int steps) {
    node* cur = obj->curr;
    while(cur->prev  && steps > 0) {
        cur = cur->prev;
        steps--;
    }
    if (cur && cur != obj->head->prev && steps == 0) {
        obj->curr = cur;
        return cur->url;
    } else {
        obj->curr = obj->head;
        return obj->curr->url;
    }
}

char* browserHistoryForward(BrowserHistory* obj, int steps) {
    node* cur = obj->curr;
    while(cur->next && steps > 0) {
        cur = cur->next;
        steps--;
    }
    obj->curr = cur;
    return cur->url;

}

void browserHistoryFree(BrowserHistory* obj) {
    free(obj);
}
