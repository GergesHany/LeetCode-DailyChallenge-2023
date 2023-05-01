class Solution {
#define sz(s) int(s.size())
public:
  vector < bool > vis;
  unordered_map < int, vector < pair < int, int > > > adj;
  
  void dfs(int node, int &ans) {
    vis[node] = true;
    for (auto &x : adj[node]) {
      if (!vis[x.first]) {
        ans = min(ans, x.second);
        dfs(x.first, ans);
      }else{
        ans = min(ans, x.second);
      }
    }
  }

  int minScore(int n, vector<vector<int>>& roads) {
    vis = vector < bool > (n + 5, false);
    for (auto &x : roads) {
      adj[x[0]].push_back({x[1], x[2]});
      adj[x[1]].push_back({x[0], x[2]});
    } 
    
    int ans = 1e9;
    dfs(1, ans);
    return ans;
  }
};