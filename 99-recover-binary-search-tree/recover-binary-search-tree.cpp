class Solution {
public:
    void solve(TreeNode* root, vector<int>&ans, int &i)
    {
        if(root == NULL)
        {
            return ;
        }
        solve(root -> left, ans, i);
        root->val=ans[i];
        i=i+1;
        solve(root -> right, ans, i);
    }
    void inorder(TreeNode* root, vector<int>&ans)
    {
        if(root == NULL)
        {
            return;
        }
        inorder(root -> left, ans);
        ans.push_back(root -> val);
        inorder(root -> right, ans);
    }
    void recoverTree(TreeNode* root) {
        vector<int>ans;
        inorder(root , ans);
        sort(ans.begin(),ans.end());
        int i=0;
        solve(root ,ans, i);
        
    }
};