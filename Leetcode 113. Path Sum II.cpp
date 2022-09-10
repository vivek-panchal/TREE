class Solution {
public:
    vector<vector<int>> ans;
    void solve(TreeNode* root, int target,vector<int> temp){
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL && root->val==target){
            temp.push_back(root->val);
            ans.push_back(temp);
            return;
        }
        temp.push_back(root->val);
        solve(root->left,target-root->val,temp);
        solve(root->right,target-root->val,temp);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        solve(root,targetSum,temp);
        return ans;
    }
};
