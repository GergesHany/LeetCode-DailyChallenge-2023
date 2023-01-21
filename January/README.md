# LeetCode Daily Challenge Problems for January

<br><br>

## Problems:

1. **[Word Pattern](#1--word-pattern)**
1. **[Detect Capital](#2--detect-capital)**
1. **[Delete Column to Make Sorted](#3--delete-column-to-make-sorted)**
1. **[Minimum Rounds to Complete All Tasks](#4--minimum-rounds-to-complete-all-tasks)**
1. **[Minimum Number of Arrows to Burst Balloons](#5--minimum-number-of-arrows-to-burst-balloons)**
1. **[Maximum Ice Cream Bars](#6--maximum-ice-cream-bars)**
1. **[Gas Station](#7--gas-station)**
1. **[Max Points on Line](#8--max-points-on-a-line)**
1. **[Binary Tree Preorder Traversal](#9--binary-tree-preorder-traversal)**
1. **[Same Tree](#10--Same-Tree)**
1. **[Minimum Time to Collect All Apples in a Tree](#11--minimum-time-to-collect-all-apples-in-a-tree)**
1. **[Number of Nodes in the Sub-Tree With the Same Label](#12--number-of-nodes-in-the-sub-tree-with-the-same-label)**
1. **[Longest Path With Different Adjacent Characters](#13--longest-path-with-different-adjacent-characters)**
1. **[Lexicographically Smallest Equivalent String](#14--lexicographically-smallest-equivalent-string)**
1. **[Number of Good Paths](#15--number-of-good-paths)**
1. **[Insert Interval](#16--insert-interval)**
1. **[Flip String to Monotone Increasing](#17--flip-string-to-monotone-increasing)**
1. **[Maximum Sum Circular Subarray](#18--maximum-sum-circular-subarray)**
1. **[Subarray Sums Divisible by K](#19--Subarray-Sums-Divisible-by-K)**
1. **[Non-decreasing Subsequences](#20--non-decreasing-subsequences)**
1. **[Restore-IP-Addresses](#21--Restore-IP-Addresses)**

<hr>

<br><br>

## 1)  [Word Pattern](https://leetcode.com/problems/word-pattern/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`String` `Hash Table`

### Code


```cpp
class Solution {
#define sz(s) int(s.size())  
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s); // string stream to split the string
        vector < string > vec;
        while(ss >> s)
            vec.push_back(s); // split the string into vector of strings
        if (vec.size() != pattern.size()) return false; // if the size of the vector and the pattern are not equal return false

        map < char, string > mp; // map to store the pattern and the string
        map < string, char > mp2; // map to store the string and the pattern

        for(int i = 0 ; i < sz(pattern); i++){
           // if the pattern and the string are not found in the maps
            if(mp.find(pattern[i]) == mp.end() && mp2.find(vec[i]) == mp2.end()) 
                mp[pattern[i]] = vec[i], mp2[vec[i]] = pattern[i]; // insert them in the maps

            // if the pattern and the string are found in the maps
            else if(mp.find(pattern[i]) != mp.end() && mp2.find(vec[i]) != mp2.end()){
                if(mp[pattern[i]] != vec[i] || mp2[vec[i]] != pattern[i]) 
                    return false; // if the pattern and the string are not equal return false
            }
            else return false; // if the pattern and the string are not found in the maps return false
        }
        return true;
    }  
};
```

<hr>

<br><br>

## 2)  [Detect Capital](https://leetcode.com/problems/detect-capital/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`String`

### Code

```cpp
class Solution {
public:
    bool detectCapitalUse(string s) {
        int upper = 0;
        for (auto & i: s) 
          upper += (isupper(i) ? 1 : 0); // count the number of upper case letters
        return (upper == s.size() ) or !upper or (upper == 1 && isupper(s[0]));
    }
};
```

<hr>

<br><br>

## 3)  [Delete Column to Make Sorted](https://leetcode.com/problems/delete-columns-to-make-sorted/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`Array` `String`

### Code

```cpp
#define sz(s) int(s.size())  
#define all(vec) vec.begin(), vec.end()
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt = 0;
        for(int i = 0; i < sz(strs[0]); i++){ // loop on the columns
          string s;
          for(int j = 0; j < sz(strs); j++) 
            s += strs[j][i]; // get the column
          if(!is_sorted(all(s))) cnt++; // check if the column is not sorted
        }
        return cnt;
    }
};
```

<hr>

<br><br>

## 4)  [Minimum Rounds to Complete All Tasks](https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Array` `Hash Table` `Greedy` `Counting`

### Code

```cpp
#define ceill(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int curr = 1, ans = 0;
        sort(tasks.begin(), tasks.end()); // sort the tasks 
        for (int i = 1; i < tasks.size(); i++){
            if (tasks[i] == tasks[i - 1]) curr++; // if the current task is equal to the previous task then increment the current task
            else{ // if the current task is not equal to the previous task then we have to do the previous task
               if (curr == 1) return -1; // if the current task is 1 then we can't do it so return -1
               ans += ceill(curr, 3); // if the current task is not 1 then we can do it so we add the ceil of the current task by 3 to the answer
               // add the ceil of the current task by 3 to the answer because this is the minimum number of rounds we need to do the current task
               curr = 1; // reset the current task to 1
            }
        }
        // if the current task is 1 then we can't do it so return -1 else we can do it so we add the ceil of the current task by 3 to the answer
        return curr == 1 ? -1 : ans + ceill(curr, 3);
    }
};


// other solution
#define ceill(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
       int ans = 0; 
       map < int , int > freq;
       for (auto & i: tasks) freq[i]++; 
       for (auto & i: freq){
           if (i.second == 1) return -1;
           ans += ceill(i.second, 3);
       }
       return ans;
    }
};
```

<hr>

<br><br>

## 5)  [Minimum Number of Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Array` `Greedy` `Sorting`

### Code

```cpp
class Solution {
#define sz(s) int(s.size())
#define all(s)  s.begin(),  s.end()
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(sz(points) == 0) return 0;
        int ans = 1;
        sort(all(points));
        int end = points[0][1]; 
        for(int i = 1; i < sz(points); i++){
            if(points[i][0] > end){ 
                ans++;
                end = points[i][1]; 
            }
            else{
                end = min(end, points[i][1]); 
            }
        }
        return ans;
    }
};
```

<hr>

<br><br>

## 6)  [Maximum Ice Cream Bars](https://leetcode.com/problems/maximum-ice-cream-bars/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Array` `Greedy` `Sorting`

### Code

```cpp
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int cnt = 0, sum = 0;
        sort(costs.begin(), costs.end()); // sort the array to get the minimum cost first
        for (auto& i: costs){
          if (sum + i <= coins) sum += i, cnt++; // if the sum of the cost is less than the coins we have, we can buy it
          else break; // if the sum is greater than the coins we have, we can't buy it 
        }
        return cnt;   
    }
};
```

<br><br>

## 7)  [Gas Station](https://leetcode.com/problems/gas-station/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Array` `Greedy`

### Code

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int Idx = 0, n = gas.size(), sum = 0, total = 0;
      for(int i = 0; i < n; i++){
        sum += gas[i] - cost[i]; // sum of gas - cost from Idx to i
        total += gas[i] - cost[i]; // sum of gas - cost from 0 to i
        if(sum < 0) // if sum < 0 then we can't reach i from Idx
          Idx = i + 1, sum = 0; // so we will start from i + 1 and reset sum to 0
      }
      // if total < 0 then we can't reach any station from 0 to n - 1 
      return total >= 0 ? Idx : -1; 
    }
};
```

<br><br>

## 8)  [Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line/)

### Difficulty

**${\bf{\color\{red}\{Hard}}}$**

### Related Topic

`Array` `Hash Table` `Math` `Geometry`


### Code

```cpp
// number of points that line on the same straight line "equal" to the number of points that have the same slope
class Solution {
public: 
    // get slope between two points
    long double get_slope(int x1, int y1, int x2, int y2){
      return (x1 == x2) ? INT_MAX : (long double)(y1 - y2) / (x1 - x2);
    }

    int maxPoints(vector<vector<int>>& points) {
       int ans = 1; // at least one point
        for(int i = 0; i < points.size(); i++){
          int x = points[i][0], y = points[i][1]; // current point
          map < long double, int > mp; // slope, count
          for (int j = 0; j < points.size(); j++){
            if (i == j) continue; // same point
            int x1 = points[j][0], y1 = points[j][1]; // other point
            long double slope = get_slope(x, y, x1, y1); // get slope
            mp[slope]++; // increment count of this slope by 1
          }
          for (auto it : mp) 
            ans = max(ans, it.second); // get max count of points with same slope 
        }
        return ans; // return max count
    }
};
```

<br><br>

## 9)  [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`Stack` `Tree` `Depth-First Search` `Binary Tree`



### Code

```cpp
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
   vector < int > ans;
   // preorder function 
   void preorder(TreeNode* root){
        if (!root) return;
        // first push the root value in the vector
        ans.push_back(root -> val);
        // now recur on left subtree         
        preorder(root -> left);
        // now recur on right subtree
        preorder(root -> right); 
    }
    vector<int> preorderTraversal(TreeNode* root) {
      preorder(root);
      return ans;
    }
};
```
[implementation of the binary search tree](https://github.com/GergesHany/Data_Structure/blob/master/binary%20search%20tree/BST.cpp)


## 10)  [Same Tree](https://leetcode.com/problems/same-tree/description/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`Breadth First Search` `Tree` `Depth-First Search` `Binary Tree`



### Code

```cpp
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
      if (!p && !q) return true; // if both are null return true
      else if (!p or !q) return false; // if one of them is null and the other is not return false
      if (p -> val != q -> val) return false; // if the values are not equal return false
      // if the values are equal check the left and right subtrees
      return isSameTree(p -> right, q -> right) && isSameTree(p -> left, q -> left);
    }
};
```

<br><br>

## 11)  [Minimum Time to Collect All Apples in a Tree](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Tree` `Breadth-First Search` `Depth-First Search` `Hash Table`



### Code

```cpp
class Solution {
public:
    int dfs(int u, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &hasApple) {
        vis[u] = true; // mark the node as visited
        int ans = 0; 
        for(auto &v : adj[u]) {
            if(!vis[v]) { // if the node is not visited
                int x = dfs(v, adj, vis, hasApple); // call dfs on the node and store the result in x 
                if(x || hasApple[v]) ans += 2 + x; // if x or hasApple[v] is true then add 2 + x to the answer
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
```

## 12)  [Number of Nodes in the Sub-Tree With the Same Label](https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Tree` `Breadth-First Search` `Depth-First Search` `Hash Table` `Counting`


### Code

```cpp
 // 
```

<hr>

<br><br>

## 13)  [Longest Path With Different Adjacent Characters](https://leetcode.com/problems/longest-path-with-different-adjacent-characters/)

### Difficulty

**${\bf{\color\{red}\{Hard}}}$**

### Related Topic

`Array` `String` `Tree` `Depth-First Search` `Graph` `Topological Sort`


### Code

```cpp
class Solution {
public:
    int dfs(vector<vector<int>>& x,int& mx,int i,string& s){
        if(x[i].size() == 0) return 1; // leaf
        vector < int > e; // edges
        int mx1 = 0, mx2 = 0; 
        for(int j = 0; j < x[i].size(); j++){
            int a = dfs(x, mx, x[i][j], s); // a = longest path from x[i][j]
            if(s[x[i][j]] == s[i]) a = 0; // if same color, reset
            if(a > mx1) 
                mx2 = mx1, mx1 = a; // mx1 = longest path, mx2 = second longest path
            else if(a > mx2) mx2 = a; // mx2 = second longest path
        }
        mx = max(mx, mx1 + mx2 + 1); // update answer
        return mx1 + 1;
    }

    int longestPath(vector<int>& par, string s) {
        int n = par.size(), mx = 1;
        vector < vector < int > > x(n, vector<int>());
        for(int i = 0; i < n; i++)
            if(~par[i]) x[par[i]].push_back(i); // build tree
        dfs(x, mx, 0, s); // call dfs
        return mx;
    }
};
```

<hr>

<br><br>

## 14)  [Lexicographically Smallest Equivalent String](https://leetcode.com/problems/lexicographically-smallest-equivalent-string/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`String` `Union Find`

### Code
```cpp
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector < char > build(26); 
        iota(all(build), 'a'); // store the letters in the vector build
        for(int i = 0; i < sz(s1); i++){
           // find the max and min of the two letters
           char maxi = max(build[s1[i] - 'a'], build[s2[i] - 'a']);
           char mini = min(build[s1[i] - 'a'], build[s2[i] - 'a']);
           
           // if the max and min are the same, then continue because they are already equivalent
           if (maxi == mini) continue;

           // if the max and min are different, then change all the max to min
           for(int i = 0; i < 26; i++)
               if(build[i] == maxi)  
                   build[i] = mini;
        }
        // change the baseStr to the smallest equivalent string
        for(auto& i : baseStr) i = build[i - 'a']; 
        return baseStr;
    }
};
```
## 15)  [Number of Good Paths](https://leetcode.com/problems/number-of-good-paths/)

### Difficulty

**${\bf{\color\{red}\{Hard}}}$**

### Related Topic

`Array` `Union Find` `Tree` `Graph`

### Code

```cpp
//
```

<br><br>

## 16)  [Insert Interval](https://leetcode.com/problems/insert-interval/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Array`

### Code

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector < vector < int > > ans;
        
        for(auto &i: intervals){
            // if the current interval is less than the new interval then push it to the answer
            if(i[1] < newInterval[0]) ans.push_back(i);
            // if the current interval is greater than the new interval then push the new interval to the answer and then push the current interval
            else if(newInterval[1] < i[0]){
                ans.push_back(newInterval);
                newInterval = i;
            }   
            else{
                // if the current interval is overlapping with the new interval then merge them and update the new interval
                newInterval[0] = min(newInterval[0], i[0]);
                newInterval[1] = max(newInterval[1], i[1]);
            }    
        }
        ans.push_back(newInterval);
        return ans;
    }
};
```

## 17)  [Flip String to Monotone Increasing](https://leetcode.com/problems/flip-string-to-monotone-increasing/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`String` `Dynamic Programming`

### Code

```cpp
class Solution {
public:
    int minFlipsMonoIncr(string s) {
      int n = s.size();
      vector < vector < int > > dp(n + 1, vector < int > (2, 0));
      if (s[0] == '0') dp[0][0] = 0, dp[0][1] = 1; // cost of flipping 0 to 1
      else dp[0][0] = 1, dp[0][1] = 0; // cost of flipping 1 to 0
      for (int i = 1; i < n; i++){
        if (s[i] == '0'){
          dp[i][0] = dp[i - 1][0]; // cost of flipping 0 to 0
          dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1; // cost of flipping 1 to 0
        }
        else{
          dp[i][0] = dp[i - 1][0] + 1; // cost of flipping 0 to 1
          dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]); // cost of flipping 1 to 1
        }
      }

      return min(dp[n - 1][0], dp[n - 1][1]); // return min cost of flipping 0 to 1 or 1 to 0
    }
};
```

<br><br>

## 18)  [Maximum Sum Circular Subarray](https://leetcode.com/problems/maximum-sum-circular-subarray/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`String` `Dynamic Programming`

### Code

```cpp
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // Kadane's Algorithm
        int totalSum = 0, maxSum = INT_MIN, curMax = 0, minSum = INT_MAX, curMin = 0;
        for (int x : nums) {
            curMax = max(x, curMax + x);  // max sum of the subarray
            maxSum = max(maxSum, curMax); // update the max sum of the subarray
            curMin = min(x, curMin + x);  // min sum of the subarray
            minSum = min(minSum, curMin); // update the min sum of the subarray
            totalSum += x; // sum of the array
        }
        // if the max sum of the subarray is greater than 0 then we can subtract the min sum of the subarray from the total sum of the array to get a max circular subarray
        // else we can't subtract the min sum of the subarray from the total sum of the array
        return maxSum > 0 ? max(maxSum, totalSum - minSum) : maxSum;
    }
};
```

<br><br>

## 19)  [Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`String` `prefix sum` `Hash Table`

### Code

```cpp
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int cumSum = 0; // sum of the subarray
        int n = nums.size(); 
        vector < int > mod(k, 0); // build the mod of the sum of the subarray

        for (int i = 0; i < n; i++) {
            cumSum += nums[i]; // sum of the subarray
            mod[((cumSum % k) + k) % k]++; // mod of the sum of the subarray 
        }

        int ans = 0; 
        for (int i = 0; i < k; i++)
        // if the mod of the sum of the subarray is greater than 1
        // then we can subtract the two subarrays to get a subarray with sum = 0
            if (mod[i] > 1) 
                ans += (mod[i] * (mod[i] - 1)) / 2;


        return ans + mod[0]; // add the subarrays with sum = 0
    }
};
```

<br><br>

## 20)  [non-decreasing-subsequences](https://leetcode.com/problems/non-decreasing-subsequences/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Array` `Hash Table` `Backtracking` `Bit Manipulation`

### Code

```cpp
class Solution {
#define all(vec)  vec.begin(),  vec.end()  
public:
    set < vector < int > > ans; // to avoid duplicates
    void Get_all(vector < int >& vec, int Idx, vector < int > build){
       if (Idx == vec.size()){ // base case
          if (is_sorted(all(build)) && build.size() > 1)  // check if it's sorted and not empty
            ans.insert(build); // insert it in the set
          return;
       }
       // recursive case
       Get_all(vec, Idx + 1, build); // don't take the current element
       build.push_back(vec[Idx]); // take the current element
       Get_all(vec, Idx + 1, build); // take the current element
       build.pop_back(); // backtracking
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        Get_all(nums, 0, {}); // call the function
        vector < vector < int > > res(all(ans)); // convert the set to vector of vectors
        return res;
    }
};
```


## 21)  [Restore-IP-Addresses](https://leetcode.com/problems/restore-ip-addresses/description/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`String` `Backtracking`

### Code

```cpp
class Solution {
#define sz(s) int(s.size())
#define all(s) s.begin(), s.end()
public:
    // function to check if the string is valid or not
    bool is_good(string s){
      // if the point is not 3 and the first character is equal to . is not valid
      if (count(all(s), '.') != 3 || s[0] == '.') return false;

      // store the index of the point to check the string between the points
      vector < int > point;
      for (int i = 0; i < sz(s); i++) if (s[i] == '.') point.push_back(i);
      point.push_back(sz(s)); // add the last index of the string to check the last string

      // check the first string 
      string temp = s.substr(0, point[0]);
      if (stoll(temp) > 255 || (temp[0] == '0' && sz(temp) > 1)) return false;
      // check the other strings between the points
      for (int i = 1; i < sz(point); i++){
        string temp = s.substr(point[i - 1] + 1, point[i] - point[i - 1] - 1);
        if (stoll(temp) > 255 || (temp[0] == '0' && sz(temp) > 1)) return false;
      }
      return true;
    }

    vector < string > build;
    void Backtracking(int Idx, string s){
        if (Idx == sz(s)) {
          // if the string is valid push it to the vector
           if (is_good(s)) build.push_back(s);
           return;
        }
        // if the string is equal to . call the function again to check the next character 
        if (s[Idx] == '.') Backtracking(Idx + 1, s);
        else{
          // if the string is not equal to . add the point and call the function again to check the next character
           Backtracking(Idx + 1, s);
           s.insert(Idx, ".");
           Backtracking(Idx + 2, s);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        Backtracking(0, s); // call the function to check the string
        return build; // return the answer
    }
};
```
