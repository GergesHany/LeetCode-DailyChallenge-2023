class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
      int ans = 0; // max distance
      int n = grid.size(), m = grid[0].size(); // size of grid
      vector < pair < int, int > > ones, zeros; // store coordinates of ones and zeros
      // lambda function to calculate distance between two points
      auto Distance = [&](int x, int y, int i, int j){
          return abs(x - i) + abs(y - j);
      };

      for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
          // store coordinates of ones and zeros
          if(grid[i][j] == 1) ones.push_back({i, j}); 
          else zeros.push_back({i, j});
      
      // if there is no ones or zeros return -1 
      if (!ones.size() || !zeros.size()) return -1;

      // for each zero find the minimum distance to one
      for(auto [x, y] : zeros){
        int mn = 1e9;
        for(auto [i, j] : ones)
          mn = min(mn, Distance(x, y, i, j));  // update the minimum distance
        ans = max(ans, mn); // update the answer
      }
      return ans; // return the answer
    }
};
