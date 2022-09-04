class Solution {
public:
    bool solve(TreeNode* p,TreeNode* q){
        if(p==NULL && q==NULL)
            return true;
        if(p!=NULL && q==NULL)
            return false;
        if(p==NULL && q!=NULL)
            return false;
        if(p->val!=q->val)
            return false;
        return solve(p->left,q->right) && solve(p->right , q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return solve(root->left,root->right);
    }
};
