#include<stdbool.h>

bool isValid(char* s) {
    char stack[1000];
    int top = -1;

    char map[256] = {0};
    map[')'] = '(';
    map['}'] = '{';
    map[']'] = '[';
    //s[i] != '\0' is useful when iterating strings in C
    for (int i=0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == ')' || c == '}' || c == ']'){
            if (top != -1 && stack[top] == map[c]){
                top--;
            }
            else {
                 return false;
            }
        } else {
            stack[++top] = c;
        }
    }
    return top == -1;
}
