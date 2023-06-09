## LeetCode Daily Challenge Problems for June


## Problems :


1. **[Shortest Path in Binary Matrix](#1-shortest-path-in-binary-matrix)**
1. **[Detonate the Maximum Bombs](#2-detonate-the-maximum-bombs)**
1. **[Time Needed to Inform All Employees](#3-time-needed-to-inform-all-employees)**
1. **[Number of Provinces](#4-number-of-provinces)**
1. **[Check If It Is a Straight Line](#5-check-if-it-is-a-straight-line)**
1. **[Can Make Arithmetic Progression From Sequence](#6-can-make-arithmetic-progression-from-sequence)**
1. **[Minimum Flips to Make a OR b Equal to c](#7-minimum-flips-to-make-a-or-b-equal-to-c)**
1. **[Count Negative Numbers in a Sorted Matrix](#8-count-negative-numbers-in-a-sorted-matrix)**


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


## 3) [Time Needed to Inform All Employees](https://leetcode.com/problems/time-needed-to-inform-all-employees/)

### Difficulty

**${\bf{\color\{orange}{Medium}}}$**

### Related Topic

**[Tree](https://leetcode.com/tag/tree/)** , **[Depth-first Search](https://leetcode.com/tag/depth-first-search/)** , **[Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)**


### Code

```cpp
class Solution {
public:

    int curr = 0, ans = 0; // curr is the current time taken to inform all the subordinates of a manager
    
    // dfs to find the maximum time taken to inform all the subordinates of a manager
    void dfs(vector < int > adj[], vector < int >& informTime, int src){
        // if the manager has no subordinates, then update the ans 
        if(adj[src].size() == 0){
            ans = max(ans, curr);
            return ;
        }
        // else, update the current time taken to inform all the subordinates of the manager
        curr += informTime[src];
        // call dfs for all the subordinates of the manager
        for(auto it : adj[src])
            dfs(adj, informTime, it);
        // backtrack    
        curr -= informTime[src];
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector < int > adj[n]; // adjacency list to store the subordinates of a manager

        // create the adjacency list
        for(int i = 0; i < n; i++)
            if(~manager[i])
                adj[manager[i]].push_back(i);
        // call dfs for the headID
        dfs(adj, informTime, headID);

        // return the ans
        return ans;
    }
};
```

### Time Complexity

**O(N)**

### Space Complexity

**O(N)**

### Useful Links

[![Link](http://img.youtube.com/vi/0XgVhsMOcQM/0.jpg)](http://www.youtube.com/watch?v=0XgVhsMOcQM "")

### Similar Problems

- [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
- [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)


<br><hr>



## 4) [Number of Provinces](https://leetcode.com/problems/number-of-provinces/)


### Difficulty

**${\bf{\color\{orange}{Medium}}}$**

### Related Topic

**[Graph](https://leetcode.com/tag/graph/)** , **[Depth-first Search](https://leetcode.com/tag/depth-first-search/)** , **[Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)** , **[Union Find](https://leetcode.com/tag/union-find/)**


### Code

```cpp
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
```

### Time Complexity

**O(N + M)**

### Space Complexity

**O(N * N)**


### Useful Links

[![Link](https://www.youtube.com/watch?v=R4Nh-EgWjyQ)](https://www.youtube.com/watch?v=R4Nh-EgWjyQ "")

### Similar Problems


- [Number of Connected Components in an Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)

- [Robot Return to Origin](https://leetcode.com/problems/robot-return-to-origin/)

- [Detonate the Maximum Bombs](https://leetcode.com/problems/detonate-the-maximum-bombs/)



<br><hr>


## 5) [Check If It Is a Straight Line](https://leetcode.com/problems/check-if-it-is-a-straight-line/)


### Difficulty

**${\bf{\color\{green}{Easy}}}$**

### Related Topic

**[Math](https://leetcode.com/tag/math/)** , **[Geometry](https://leetcode.com/tag/geometry/)** , **[Array](https://leetcode.com/tag/array/)**


### Code

```cpp
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = int(coordinates.size()); // size of coordinates

        // if there are only 2 points, return true
        if (n == 2) return true;

        // if there are more than 2 points, check if they are on the same line 

        // check if the slope of the first 2 points are the same with the rest of the points 
        int x1 = coordinates[0][0], y1 = coordinates[0][1];
        int x2 = coordinates[1][0], y2 = coordinates[1][1];
        
        // if the slope of the first 2 points are the same with the rest of the points, return true
        for (int i = 2; i < n; ++i){
            int x3 = coordinates[i][0], y3 = coordinates[i][1];
            if ((y2 - y1) * (x3 - x2) != (y3 - y2) * (x2 - x1)) return false;
        }
        
        // if the slope of the first 2 points are not the same with the rest of the points, return false
        return true;
    }
};
```

### Time Complexity

**O(N)**

### Space Complexity

**O(1)**


### Useful Links

[![Link](https://www.youtube.com/watch?v=R948Tsyq4vA)](https://www.youtube.com/watch?v=R948Tsyq4vA "")



<br><hr>


## 6) [Can Make Arithmetic Progression From Sequence](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/)


### Difficulty

**${\bf{\color\{green}{Easy}}}$**

### Related Topic

**[Array](https://leetcode.com/tag/array/)** , **[Sorting](https://leetcode.com/tag/sorting/)** , **[Math](https://leetcode.com/tag/math/)**


### Code

```cpp
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        // sort the array
        sort(arr.begin(), arr.end()); 
        
        // check if the difference between first two elements is same as the difference between the next two elements
        for (int i = 1; i < int(arr.size()); i++)
           // if the difference is not same, return false
            if ((arr[i] - arr[i - 1]) != (arr[1] - arr[0]))
               return false;
        // if the difference is same, return true
        return true;
    }
};
```

### Time Complexity

**O(N log N)**

### Space Complexity

**O(1)**


### Useful Links

[![Link](https://www.youtube.com/watch?v=MOaSXYGas0I)](https://www.youtube.com/watch?v=MOaSXYGas0I "")


### Similar Problems

- [Arithmetic Subarrays](https://leetcode.com/problems/arithmetic-subarrays/)

<br><hr>


## 7) [Minimum Flips to Make a OR b Equal to c](https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/)


### Difficulty

**${\bf{\color\{orange}{Medium}}}$**

### Related Topic

**[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)**


### Code

```cpp
class Solution {
public:
    int minFlips(int a, int b, int c) {
      int ans = 0; // the number of flips

      // convert to binary representation using bitset
      bitset < 32 > A(a), B(b), C(c);
      
      for (int i = 0; i < 32; i++){
        // check if the ith bit of c is different from the ith bit of a or b
        if ((A[i] | B[i]) != C[i]){
          // if the ith bit of c is 0, we need to flip both a and b  
          if (C[i] == 0) ans += (A[i] + B[i]);
          // if the ith bit of c is 1, we need to flip either a or b
          else ans++;
        }
      }
      // return the number of flips
      return ans;
    }
};
```

### Time Complexity

**O(1)**

### Space Complexity

**O(1)**


### Useful Links

[![Link](https://www.youtube.com/watch?v=taov2H_-nlU)](https://www.youtube.com/watch?v=taov2H_-nlU "")


### Similar Problems

- [Minimum Bit Flips to Convert Number](https://leetcode.com/problems/minimum-bit-flips-to-convert-number/) 

<br><hr>



## 8) [Count Negative Numbers in a Sorted Matrix](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/)


### Difficulty

**${\bf{\color\{green}{Easy}}}$**

### Related Topic

**[Array](https://leetcode.com/tag/array/)** , **[Binary Search](https://leetcode.com/tag/binary-search/)** , **[Matrix](https://leetcode.com/tag/matrix/)**


### Code

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0; // count of negative numbers
        for (auto & i: grid) 
        // for each row, count the number of negative numbers in it and add to ans 
          ans += count_if(i.begin(), i.end(), [](int x){ return x < 0; });
        // return the answer  
        return ans;
    }
};
```

### Time Complexity

**O(N * N)**

### Space Complexity

**O(1)**


### Useful Links

[![Link](https://www.youtube.com/watch?v=TmU8_LvroSI)](https://www.youtube.com/watch?v=TmU8_LvroSI "")


### Similar Problems

- [Maximum Count of Positive Integer and Negative Integer](https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/)


<br><hr>

