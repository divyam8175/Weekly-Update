/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
void solve(TreeNode*root,unordered_map<int,pair<int,int>>&mpp,int depth,int parent) {
    if(root==NULL) return;

    mpp[root->val]={depth,parent};
    solve(root->left,mpp,depth+1,root->val);
    solve(root->right,mpp,depth+1,root->val);
    return;
}
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int, pair<int, int>> mpp;
        solve(root,mpp,0,-1);
        if(mpp[x].first == mpp[y].first && mpp[x].second != mpp[y].second) return true;
        return false;
    }
};