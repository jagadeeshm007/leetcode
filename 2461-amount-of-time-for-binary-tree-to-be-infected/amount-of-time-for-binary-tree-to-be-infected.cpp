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
    map<int,vector<int>> mp;
    void adjusent(TreeNode* root){
        if(root==NULL) return;
        if(root->left != NULL){
            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);
        } 
        if(root->right != NULL){
            mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val);
        }
        adjusent(root->left);
        adjusent(root->right);
        
    }
    int amountOfTime(TreeNode* root, int start) {
        adjusent(root);
        queue<int> q;
        unordered_map<int,int> visited;
        q.push(start);
        int c=0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                visited[q.front()]++;
                for(auto i : mp[q.front()])
                {
                    if(visited.find(i)==visited.end()){
                        visited[i]++;
                        q.push(i);
                    }
                }
                q.pop();
            }
            c++;
        }

        /*for(auto i: mp){
            cout<<i.first<<"\n";
            for(auto j: i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }*/
        return c-1;
    }
};