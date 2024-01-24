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
    int gen(int pp,int mask){
        return (pp & mask) ? (pp & ~mask) : (pp | mask);
    }
    int valid(int pp){
        int bits =  __builtin_popcount(pp);
        return (bits==1 || bits==0) ? 1 : 0;
    }
    void dfs(TreeNode* root ,int pp){
        if (!root) return;
        pp = gen( pp , 1 << root->val );
        if (!root->left && !root->right) {
            c += valid(pp);
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