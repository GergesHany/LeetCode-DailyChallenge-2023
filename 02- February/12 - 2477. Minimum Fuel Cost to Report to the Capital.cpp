class Solution {
 public:
  long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    long long ans = 0;
    vector<vector<int>> graph(roads.size() + 1); // graph[i] = {j, k, ...} means i is connected to j, k, ...
    
    // build graph
    for (const vector<int>& road : roads) {
      int u = road[0]; 
      int v = road[1]; 
      graph[u].push_back(v); // u is connected to v
      graph[v].push_back(u); // v is connected to u
    }
    
    // call dfs
    dfs(graph, 0, -1, seats, ans);
    return ans;
  }

 private:
  int dfs(const vector<vector<int>>& graph, int u, int prev, int seats, long long& ans) {
    int people = 1; // # of people in subtree rooted at u
    for (const int v : graph[u]) { // v is a child of u
      if (v == prev) continue; // skip parent
      // # of people in subtree rooted at v
      people += dfs(graph, v, u, seats, ans);
    }
    // # of people in subtree rooted at u - # of seats in subtree rooted at u
    if (u > 0)
      ans += (people + seats - 1) / seats; // add cost of this subtree
    return people; // return # of people in subtree rooted at u
  }
};
