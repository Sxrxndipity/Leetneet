#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* create(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}


struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (!root) {
        return create(val);
    }
    if (val < root->val) {
        root->left = insertIntoBST(root->left,val);
    } else if (val > root->val) {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}
