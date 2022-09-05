class Solution {
public:
    int solve(TreeNode* root){
        if(root==NULL)
            return 0;
        int left=solve(root->left);
        int right =solve(root->right);
        if(left>0 && right>0)
            return 1+ min(left,right);
        else
            return 1+ max(left,right);
    }
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        return solve(root);
    }
};
