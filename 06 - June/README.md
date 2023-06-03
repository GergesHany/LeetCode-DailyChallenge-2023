## LeetCode Daily Challenge Problems for June


## Problems :


1. **[Shortest Path in Binary Matrix](#1-shortest-path-in-binary-matrix)**
1. **[Detonate the Maximum Bombs](#2-detonate-the-maximum-bombs)**

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

### [![Useful Links](http://img.youtube.com/vi/0XgVhsMOcQM/0.jpg)](http://www.youtube.com/watch?v=0XgVhsMOcQM "")

### Similar Problems

[Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)


<br><hr>


## 2) [Detonate the Maximum Bombs](https://leetcode.com/problems/detonate-the-maximum-bombs/description/)

### Difficulty

**${\bf{\color\{orange}{Medium}}}$**

### Related Topic

**[Graph](https://leetcode.com/tag/graph/)** , **[Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)** , **[Matrix](https://leetcode.com/tag/matrix/)**


### Code

```cpp
class Solution {
#define ll long long
public:
    
    // dfs to find the number of nodes in the connected component
    void dfs(int src, vector < int >& vis, vector < int > adj[]){
        vis[src] = true;
        for(int x: adj[src])
            if(!vis[x])
                dfs(x,vis,adj);
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
    
        int n = bombs.size(); // number of nodes
        vector < int > adj[n]; // adjacency list

        for(int i = 0; i < n; i++){
            
            // check if the bomb can destroy other bombs in the same connected component 
            ll r1 = bombs[i][2], x1 = bombs[i][0], y1 = bombs[i][1];
            
            // check if the bomb can destroy other bombs in the same connected component 
            for(int j = 0; j < n; j++){
                if (i == j) continue;
                // check if the bomb can destroy other bombs in the same connected component
                ll x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                ll dsq = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                // if the bomb can destroy other bombs in the same connected component
                if(dsq <= r1 * r1)
                    adj[i].push_back(j); 
            }
        
        }

        ll ans = 0; // answer
        vector < int > vis(n); // visited array
        for(int i = 0; i < n; i++){
            int cnt = 0; // number of nodes in the connected component
            dfs(i, vis, adj); 
            // count the number of nodes in the connected component
            for(int j = 0; j < n; j++) 
              if(vis[j] == 1) cnt++;

            // update the answer
            ans = max(ans, 1LL * cnt);
            // 
            fill(vis.begin(), vis.end(), 0);
        }
        // return the answer
        return ans;
    }
};
```

### Time Complexity

**O(N * N)**

### Space Complexity

**O(N * N)**

### Useful Links

[![Link](http://img.youtube.com/vi/0XgVhsMOcQM/0.jpg)](http://www.youtube.com/watch?v=0XgVhsMOcQM "")

### Similar Problems

- [Number of Provinces](https://leetcode.com/problems/number-of-provinces/)
- [Max Area of Island](https://leetcode.com/problems/max-area-of-island/)
- [Rotting Oranges](https://leetcode.com/problems/rotting-oranges/)


<br><hr>






