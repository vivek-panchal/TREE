class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        return max(height(root->left),height(root->right))+1;
    }
    int diameter(TreeNode* root){
        if(root==NULL)
            return 0;
        int leftTree=diameter(root->left);
        int rightTree=diameter(root->right);
        int rootNode=height(root->left)+height(root->right)+1;
        
        return max({leftTree,rightTree,rootNode});
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root)-1;
    }
};
