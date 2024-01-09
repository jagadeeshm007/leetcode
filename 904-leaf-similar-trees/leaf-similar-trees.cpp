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
    vector<int> v;
    void tree(TreeNode* root){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) v.push_back(root->val);
        tree(root->left);
        tree(root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        tree(root1);
        vector<int> v1(v.begin(),v.end());
        v.clear();
        tree(root2);
        return v1==v;
    }
};