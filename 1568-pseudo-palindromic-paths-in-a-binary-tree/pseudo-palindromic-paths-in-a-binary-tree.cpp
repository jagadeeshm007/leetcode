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
    int valid(unordered_map<int,int> &mp) {
        int ods = 0;
        for(auto i : mp) {
            if(i.second&1) ods++;
            if(ods>1){
                return 0;
            }
        }
        return 1;
    }
    void dfs(TreeNode* root ,unordered_map<int,int> mp){
        mp[root->val]++;
        if (!root) return;   
        if (!root->left && !root->right) {
            c+=valid(mp);
            return;
        }
        if (root->left) dfs(root->left,mp);
        if (root->right) dfs(root->right,mp);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> mp;
        dfs(root,mp);
        return c;
    }
};