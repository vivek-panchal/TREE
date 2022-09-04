// leetcode 144 preorder
class Solution {
public:
    vector<int> ans;
    void solve(TreeNode* root){
        if(root==NULL)
            return;
        ans.push_back(root->val);
        solve(root->left);
        solve(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        solve(root);
        return ans;
    }
};

// Leetcode 94 Inorder
class Solution {
public:
    void solve( TreeNode* root , vector<int> &ans){
        if(root==NULL)
            return;
        
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};

// Leetcode 145 Postorder
class Solution {
public:
    vector<int> ans;
    void solve(TreeNode* root){
        if(root==NULL)
            return;
        solve(root->left);
        solve(root->right);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        solve(root);
        return ans;
    }
};

// leetcode 102 level order
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
       // ager root ho hi na , tree empty hai
        if(root==NULL)  
          return {};
        // vector bna lo answer store karne ke liye 
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        // queue me root dal di
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> temp;
            for(int i = 0; i < n; ++i) {
                // tu nikal
                TreeNode* node = q.front();
                q.pop();
                // node ko temp me dal lo baad me temp ko ans me dal denge bcs vector of vector return karna hai
                temp.push_back(node -> val);
                // bache chod ja 
                if(node -> left)    q.push(node -> left);
                if(node -> right)    q.push(node -> right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


// Leetcode 103 Zig zag traversal

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // ager root ho hi na , tree empty hai
        if(!root)   return {};
        // vector bna lo answer store karne ke liye 
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        // queue me root dal di
        q.push(root);
        // ager flag true hoga to jaisa temp hai usko vaisa hi dal denge & ager flag false hua to temp ko reverse kar ke dalenge 
        bool flag = true;
        while(!q.empty()) {
            
            int n = q.size();
            vector<int> temp;
            for(int i = 0; i < n; ++i) {
                // tu nikal
                TreeNode* node = q.front();
                q.pop();
                // node ko temp me dal lo baad me temp ko ans me dal denge bcs vector of vector return karna hai
                temp.push_back(node -> val);
                // bache chod ja 
                if(node -> left)    q.push(node -> left);
                if(node -> right)    q.push(node -> right);
            }
            if(flag){
                ans.push_back(temp);
                // flag ko change kar do next iteration ke liye 
                flag=false;
            }
            else
            {
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
                // flag ko change kar do next iteration ke liye 
                flag=true;
            }
            
        }
        return ans;
    }
};
