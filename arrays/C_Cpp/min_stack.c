#include<stdlib.h>

typedef struct {
    int* stack;
    int* min_stack;
    int top;
    int capacity;
    int size;
} MinStack;


MinStack* minStackCreate() {
    MinStack* ms1 = (MinStack*)malloc(sizeof(MinStack));
    ms1->top = -1;
    ms1->capacity = 10;
    ms1->stack = (int*)malloc(sizeof(int) * ms1->capacity);
    ms1->min_stack = (int*)malloc(sizeof(int) * ms1->capacity);
    ms1->size = 0;
    return ms1;
}

void minStackPush(MinStack* obj, int val) {
    if (obj->size == obj->capacity){
        obj->capacity *= 2;
        obj->stack = (int*)realloc(obj->stack, obj->capacity);
        obj->min_stack = (int*)realloc(obj->min_stack, obj->capacity);
    }
    obj->top++;
    obj->stack[obj->top] = val;
    obj->size++;
    if (obj->top == 0){
        obj->min_stack[obj->top] = val;
    } else {
        obj->min_stack[obj->top] = (val < obj->min_stack[obj->top - 1]) ? val : obj->min_stack[obj->top - 1];
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top != -1) {
        obj->top--;
        obj->size--;
    }
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->min_stack[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj->min_stack);
    free(obj);
}
