class Solution {
public:
    int count=0;
    void solve(TreeNode* root, int target,long long int sum){
        if(root==NULL)
            return ;
        if(target==sum)
            count++;
        if(root->left!=NULL)
            solve(root->left,target,sum+root->left->val);
        if(root->right!=NULL)
            solve(root->right,target,sum+root->right->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (root==NULL)
            return 0;
        solve(root,targetSum,root->val);
        
        // solve for left & Right part
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return count;
    }
};
