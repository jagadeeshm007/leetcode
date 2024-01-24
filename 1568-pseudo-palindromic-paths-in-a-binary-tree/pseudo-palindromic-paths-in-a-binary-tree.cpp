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
    int c=0;
    void dfs(TreeNode* root ,int pp){
        if (!root) return;
        pp ^= 1 << root->val;
        if (!root->left && !root->right) {
            c += (!pp or !(pp-1 & pp));
            return;
        }
        dfs(root->left,pp);
        dfs(root->right,pp);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root,0);
        return c;
    }
};