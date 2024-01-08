class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int,vector<int>> mp;
        vector<int> v;
        int n=mat.size();
        for(int i=0;i<mat.size();i++){
            int b = lower_bound(mat[i].rbegin(),mat[i].rend(),1)-mat[i].rbegin();
            if(b==0){
                mp[n].push_back(i);
            } 
            else{
                 mp[(n-b)].push_back(i);
            }

        }
        for(auto i : mp){
            for(auto j : i.second){
                if(k == 0) break;
                v.push_back(j);
                k--;
            }
            if(k==0) break;
        }
        return v;
    }
};