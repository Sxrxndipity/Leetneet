struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {

    if (!root || root == p || root == q) {
        return root;
    }
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) {
        return root;
    }
    return left ? left : right;
}
/*
* alternatively
 struct TreeNode* cur = root;
 while (cur) {
   if ((p->val < cur->val) && (q->val < cur->val)) {
       cur = cur->left;
   } else if ((p->val > cur->val) && (q->val > cur->val)) {
       cur = cur->right;
   } else {
       return cur;
   }

 }
*/
