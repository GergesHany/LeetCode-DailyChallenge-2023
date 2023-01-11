class Solution {
public:

    int dfs(int u, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &hasApple) {
        vis[u] = true;
        int ans = 0;
        for(auto &v : adj[u]) {
            if(!vis[v]) {
                int x = dfs(v, adj, vis, hasApple);
                if(x || hasApple[v]) ans += 2 + x;
            }
        }
        return ans;
    } 

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
         vector < bool > vis(n);
         vector < vector < int > > adj(n);
          for(auto &e : edges) 
            adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);            
          return dfs(0, adj, vis, hasApple);
    }
};