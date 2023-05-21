class Solution {
#define sz(x) int(x.size())  
public:
   int cnt = 1; // number of components
   vector < vector < bool > > vis; // visited array
   vector < pair < int, int > > comp1, comp2; // components

   // dfs function
   void dfs(int i, int j, vector < vector < int > > &grid){
     // if the cell is out of the grid or it is visited or it is water
     if (i < 0 || j < 0 || i >= sz(grid) || j >= sz(grid[0]) || vis[i][j] || !grid[i][j]) return;
     // mark the cell as visited
     vis[i][j] = true;

     // if the component is 1 or 2
     if (cnt == 1) comp1.push_back({i, j});
     else comp2.push_back({i, j});
     
     // call dfs for the adjacent cells
     dfs(i + 1, j, grid);
     dfs(i - 1, j, grid);
     dfs(i, j + 1, grid);
     dfs(i, j - 1, grid);
   }

    int shortestBridge(vector<vector<int>>& grid) {

      // initialize the visited array
      vis = vector < vector < bool > > (sz(grid), vector < bool > (sz(grid[0])));

      for (int i = 0; i < sz(grid); i++){
        for (int j = 0; j < sz(grid[0]); j++){
          // if the cell is land and it is not visited yet
          if (grid[i][j] && !vis[i][j]){
            // call dfs to mark all the cells in the same component
            dfs(i, j, grid);
            // increase the number of components
            cnt++;
          }
        }
      }

      // find the answer
      int ans = 1e9;
      for (auto &x : comp1){
        for (auto &y : comp2){
          ans = min(ans, abs(x.first - y.first) + abs(x.second - y.second) - 1);
        }
      }
      
      // return the answer
      return ans;
    }
};