class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>res(n);
        vector<int>deg(n,0);
        for(auto i:prerequisites)
        {
            res[i[1]].push_back(i[0]);
            deg[i[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(deg[i]==0)q.push(i);
        }
        
        if(q.empty())return {};
        vector<int>ans;
        while(!q.empty())
        {
            auto a=q.front();
            ans.push_back(a);
            q.pop();
            for(auto k:res[a])
            {
                deg[k]--;
                if(deg[k]==0)q.push(k);
            }
        }

        for(int i=0;i<n;i++)if(deg[i])return {};
        return ans;
    }
};