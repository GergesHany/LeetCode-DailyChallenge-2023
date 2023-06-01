## LeetCode Daily Challenge Problems for June


## Problems :


1. **[Shortest Path in Binary Matrix](#1-shortest-path-in-binary-matrix)**

<hr>

<br><br>

## 1) [Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/description/)

### Difficulty

**${\bf{\color\{orange}{Medium}}}$**

### Related Topic

**[Graph](https://leetcode.com/tag/graph/)** , **[Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)** , **[Matrix](https://leetcode.com/tag/matrix/)** 


### Code

```cpp
class Solution {
public:
  
  // dx, dy for 8 directions
  int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
  int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};


  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = int(grid.size()); // size of grid

    // dis[i][j] = distance from (0, 0) to (i, j)
    vector < vector < int > > dis(n, vector < int > (n, 1e9));
    
    // queue for bfs
    queue < pair < int, int > > q;
    
    // if start or end is blocked, return -1
    if (grid[0][0]) return -1;
    
    // start bfs from (0, 0) and mark distance as 1     
    q.push({0, 0}), dis[0][0] = 1;

    // bfs
    while (!q.empty()){
      auto [x, y] = q.front();
      q.pop();
      // check all 8 directions
      for (int i = 0; i < 8; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] == 1) continue;
        if (dis[nx][ny] > dis[x][y] + 1){
          dis[nx][ny] = dis[x][y] + 1;
          q.push({nx, ny});
        }
      }
    }
    
    // return distance of (n - 1, n - 1) if reachable else -1
    int ans = dis[n - 1][n - 1];      
    // if (n - 1, n - 1) is not reachable, ans will be 1e9 which is not possible 
    return ans == 1e9 ? -1 : ans;
  }
};
```

### Time Complexity

**O(N * M)**

### Space Complexity

**O(N * M)**

### Useful Links

[![](http://img.youtube.com/vi/0XgVhsMOcQM/0.jpg)](http://www.youtube.com/watch?v=0XgVhsMOcQM "")

### Similar Problems

[Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)


<br><hr>

