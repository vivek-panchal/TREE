class Solution {
public:
    bool hasPathSum(TreeNode* root, int target) {
        if(root==NULL)
            return false;
        if(root->left==NULL && root->right==NULL && root->val==target ){
            return true;
        }
        bool left=hasPathSum(root->left,target-root->val);
        bool right=hasPathSum(root->right,target-root->val);
        
        return left || right;
    }
};
