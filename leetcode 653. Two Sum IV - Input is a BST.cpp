// ****************************approach*****************************
// find inorder traversal bcs inorder traversal of bst is sorted and than apply 2 sum/2 pointer approach on inorder array.
class Solution {
public:
    vector<int> inorder;
    void findInorder(TreeNode* root){
        if(root==NULL)
            return ;
        findInorder(root->left);
        inorder.push_back(root->val);
        findInorder(root->right);
        
    }
    bool findTarget(TreeNode* root, int k) {
        
        findInorder(root);
        int n=inorder.size();
        if(n==1)
            return false;
        int start=0;
        int end=n-1;
        while(start<end){
            if(inorder[start]+inorder[end]==k)
                return true;
            if(inorder[start]+inorder[end]>k)
                end--;
            if(inorder[start]+inorder[end]<k)
                start++;
        }
        return false;
    }
};
