class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) {
            return true;
        }
        vector<int> visit(n,0);
        map<int,vector<int>> graph;
        queue<int> q;
        q.push(source);
        visit[source]=1;

        for(auto node : edges ) {
            graph[node[0]].push_back(node[1]);
            graph[node[1]].push_back(node[0]);
        }

        while(!q.empty()){
            for(auto vertex : graph[q.front()]){
                if(vertex==destination){
                    return true;
                }
                if(visit[vertex]==1) {
                    continue;
                }
                q.push(vertex);
                visit[vertex]=1;
            }
            q.pop();
        }

        return false;
    }
};