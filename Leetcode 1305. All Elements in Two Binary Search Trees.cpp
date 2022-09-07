class Solution {
public:
    vector<int>ans;
    void solve(TreeNode* root){
        if(root==NULL)
            return;
        solve(root->left);
        ans.push_back(root->val);
        solve(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        solve(root1);
        solve(root2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
