class Solution {
public:
    int mini =INT_MAX;
    vector<int> temp;
    void inorder(TreeNode* root){
        if(root==NULL)
            return;
        inorder(root->left);
        temp.push_back(root->val);
        inorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        int n=temp.size();
        for(int i=0;i<n-1;i++){
            mini =min(mini,(temp[i+1]-temp[i]));
        }
        return mini;
    }
};
