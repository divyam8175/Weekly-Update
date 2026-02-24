/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int resolve(string s) {
    int sum=0;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++) {
        int n=s[i]-'0';
        sum+=(n*pow(2,i));
    }
    return sum;
}
void sum_root_to_leaf(TreeNode*root,int &sum,string s) {
    if(root->left==NULL && root->right==NULL) {
        s=s+to_string(root->val);
        cout<<s<<endl;
        int total=resolve(s);
        cout<<total<<endl;
        sum+=total;
        return;
    }
    if(root->left != NULL && root->right == NULL)
    sum_root_to_leaf(root->left,sum,s+to_string(root->val));
    if(root->left == NULL && root->right != NULL)
    sum_root_to_leaf(root->right,sum,s+to_string(root->val));
    if(root->left != NULL && root->right != NULL){
    sum_root_to_leaf(root->left,sum,s+to_string(root->val));
    sum_root_to_leaf(root->right,sum,s+to_string(root->val));
    }
    return;
}
    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        sum_root_to_leaf(root,sum,"");
        return sum;
    }
};