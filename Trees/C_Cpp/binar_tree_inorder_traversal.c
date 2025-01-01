#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// recursively count n° of tree nodes
int countNodes(struct TreeNode* root) {
    if (!root) {
        return 0;
    }
    return 1 + countNodes(root->right) + countNodes(root->left);
}

void inorder(struct TreeNode* root, int* arr, int* rs) {
    if (!root) {
        return;
    }
    inorder(root->left, arr, rs);
    arr[*rs] = root->val;
    (*rs)++;
    inorder(root->right, arr, rs);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int count = countNodes(root);

    int* res = (int*)malloc(count * sizeof(int));
    inorder(root, res, returnSize);

    return res;
}


int* it2(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int count = countNodes(root);
    struct TreeNode* stack[100];
    int sp = 0;
    int* res = (int*)malloc(count * sizeof(int));
    struct TreeNode* cur = root;

    while(cur || sp > 0) {
        while (cur) {
            stack[sp++] = cur;
            cur = cur->left;
        }
        cur = stack[--sp];
        res[*(returnSize)++] = cur->val;
        cur = cur->right;
    }
    return res;
}
