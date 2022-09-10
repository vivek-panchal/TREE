class Solution {
public:
    vector<string> ans;
    void solve(TreeNode* root, string temp){
        if (root==NULL)
            return;
        if(root->left==NULL && root->right==NULL){
            temp=temp+to_string(root->val);
            ans.push_back(temp);
            return;
        }
        temp+= to_string(root->val)+ "->";
        solve(root->left,temp);
        solve(root->right,temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string temp="";
        solve(root,temp);
        return ans;
    }
};
