#include<stdlib.h>
#include <string.h>

int calPoints(char** operations, int operationsSize) {

    int* arr = malloc(operationsSize * sizeof(int));
    int sum = 0;
    int sp = -1; // empty stack
    for (int i = 0; i < operationsSize; i++) {
        if (strcmp(operations[i], "C")==0) {
            if (sp >= 0){
                sp--;
            }
        } else if (strcmp(operations[i], "D")==0) {
            arr[sp+1] = 2 * arr[sp];
            sp++;
        } else if (strcmp(operations[i], "+")==0) {
            arr[sp+1] = arr[sp-1]+ arr[sp];
            sp++;
        } else {
            arr[sp+1] = atoi(operations[i]);
            sp++;
        }
    }
    for (int i=0; i<=sp;i++) {
        sum += arr[i];
    }
    return sum;
}

