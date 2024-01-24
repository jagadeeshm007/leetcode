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
        int mask = 1 << ((root->val) - 1);
        pp = (pp & mask) ? (pp & ~mask) : (pp | mask) ;
        if (!root->left && !root->right) {
            c+= ( __builtin_popcount(pp)==1 || __builtin_popcount(pp)==0) ? 1 : 0;
            return;
        }
        if (root->left) dfs(root->left,pp);
        if (root->right) dfs(root->right,pp);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root,0);
        return c;
    }
};