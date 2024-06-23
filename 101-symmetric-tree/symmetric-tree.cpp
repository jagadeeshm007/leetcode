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
    bool solve(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return 1;
        if(!root1 || !root2) return 0;
        if(root1->val == root2->val){
            bool p = solve(root1->left,root2->right);
            bool q = solve(root1->right,root2->left);
            return p&q;
        }
        else{
            return 0;
        }
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root,root);
    }
};