#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct {
    struct TreeNode** items;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = 0;
    q->items = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * capacity);
    return q;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, struct TreeNode* node) {
    if (q->rear == q->capacity) {
        return;
    }
    q->items[q->rear++] = node;
}

struct TreeNode* dequeue(Queue* q) {
    if (isEmpty(q)) {
        return NULL;
    }
    return q->items[q->front++];
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // Initialize the queue
    Queue* q = createQueue(1000);
    enqueue(q, root);

    // Allocate result arrays
    int** result = (int**)malloc(1000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(1000 * sizeof(int));
    *returnSize = 0;

    while (!isEmpty(q)) {
        int levelSize = q->rear - q->front;  // Number of nodes at the current level
        (*returnColumnSizes)[*returnSize] = levelSize;

        // Allocate an array to store the current level values
        result[*returnSize] = (int*)malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(q);
            result[*returnSize][i] = node->val;

            if (node->left) {
                enqueue(q, node->left);
            }
            if (node->right) {
                enqueue(q, node->right);
            }
        }

        (*returnSize)++;  // Increment the number of levels
    }

    return result;
}

