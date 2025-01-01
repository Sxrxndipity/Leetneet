struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int kthSmallest(struct TreeNode* root, int k) {
    struct TreeNode* stack[1000];
    struct TreeNode* cur = root;
    int sp = 0;
    int counter = 1;

    while(!cur || sp > 1) {
        while(cur) {
            stack[sp++] = cur;
            cur = cur->left;
        }
        cur = stack[--sp];
        if (counter == k) {
            return cur->val;
        }
        counter++;
        cur = cur->right;
    }
    return -1;
}
