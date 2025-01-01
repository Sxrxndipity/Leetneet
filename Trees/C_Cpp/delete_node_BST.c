#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int min(struct TreeNode* root);

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (!root) {
        return NULL;
    }

    if (key > root->val){
        root->right = deleteNode(root->right, key);
    }
    else if (key < root->val){
        root->left = deleteNode(root->left, key);
    }
    else {
        if (!root->right) {
            return root->left;
        }
        else if (!root->left) {
            return root->right;
        }
        else {
            int mv = min(root->right);
            root->val = mv;
            root->right = deleteNode(root->right, mv);
        }
    }


    return root;
}


int min(struct TreeNode* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root->val;
}
