
class Solution {
public:
    int ans=0;
    void solve(TreeNode* root,int digit){
        if(root->left==NULL && root->right==NULL){
            ans+= (digit*10 + root->val);
            return;
        }
        if(root->left){
            solve(root->left,digit*10 + root->val);    
        }
        if(root->right){
            solve(root->right,digit*10 + root->val);    
        }
        
        return;
    }
    int sumNumbers(TreeNode* root) {
        solve(root,0);
        return ans;
    }
};
