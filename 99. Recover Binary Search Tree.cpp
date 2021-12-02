class Solution {
public:
    TreeNode* pre = NULL, *first =  NULL, *second = NULL;
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        if(!pre) {
            pre = root;
        } else {
            if(pre->val > root->val) {
                if(!first) first = pre;
                second = root;
            }
            pre = root;
        }
        inorder(root->right);
    }
};
