class Solution {
public:
    const int N = 205; // max number of nodes
    vector < bool > vis; // visited array
    vector < int > adj[205]; // adjacency list

    // dfs function to visit all nodes in a connected component 
    void dfs(int node){
        vis[node] = true;
        for (auto & child: adj[node]){
            if (!vis[child]){
                dfs(child);
            }
        }
    
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
      int ans = 0; // number of connected components
      vis = vector < bool > (N); // visited array
      int n = isConnected.size(); // number of nodes

    //  building adjacency list
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          if (isConnected[i][j] == 1)
            adj[i].push_back(j);

      // dfs to count number of connected components
      for (int i = 0; i < n; i++){
        if (!vis[i]){
          dfs(i);
          ans++;
        }
      }

      return ans;
    }
};