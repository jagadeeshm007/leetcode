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
    int mi=0,mx=0;
    void search(TreeNode* root,vector<int> v){
        if(root==NULL) return;
        v.push_back(root->val);
        search(root->left,v);
        search(root->right,v);
        sort(v.begin(),v.end());
        if( abs(v[0]-v[v.size()-1]) > abs(mx-mi)){
            mi = v[0];
            mx = v[v.size()-1];
        }
    }
    int maxAncestorDiff(TreeNode* root) {
        vector<int> v;
        search(root,v); 
        return abs(mx-mi);       
    }
};