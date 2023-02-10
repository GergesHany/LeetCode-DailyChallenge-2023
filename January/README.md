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
1. **[Palindrome-Partitioning](#22--Palindrome-Partitioning)**
1. **[Find the Town Judge](#23--find-the-town-judge)**
1. **[Snakes and Ladders](#24--snakes-and-ladders)**
1. **[Find Closest Node to Given Two Nodes](#25--find-closest-node-to-given-two-nodes)**
1. **[Cheapest Flights Within K Stops](#26--cheapest-flights-within-k-stops)**
1. **[Concatenated Words](#27--concatenated-words)**
1. **[Data Stream as Disjoint Intervals](#28--data-stream-as-disjoint-intervals)**
1. **[LFU Cache](#29--lfu-cache)**
1. **[N-th Tribonacci Number](#30--n-th-tribonacci-number)**
1. **[Best Team With No Conflicts](#31--best-team-with-no-conflicts)**


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
<br><br>

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
    bool is_valid(string s){
      // if the point is not 3 and the first character is equal to . is not valid
      if (count(all(s), '.') != 3 || s[0] == '.') return false;
      s = "." + s;
      for (int i = 0; i < sz(s); i++){
         if (s[i] == '.'){ // if the character is equal to . check the string after it
           string temp; // temp string to check the string after the point
           for (int j = i + 1; j < sz(s) && s[j] != '.'; j++)
              temp += s[j]; // add the string to the temp string
           // if the size of the temp string is greater than 3 or equal to 0 is not valid   
           if (sz(temp) > 3 || sz(temp) == 0) return false;
           if (sz(temp) > 1 && temp[0] == '0' || stoi(temp) > 255) return false;
         }
      } 
      return true;
    }

    vector < string > build;
    void Backtracking(int Idx, string s){
        if (Idx == sz(s)) {
          // if the string is valid push it to the vector
           if (is_valid(s)) build.push_back(s);
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

<br><br>

## 22)  [Palindrome-Partitioning](https://leetcode.com/problems/palindrome-partitioning/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`String` `Backtracking` `Dynamic Programming`

### Code

```cpp
class Solution {
#define sz(s) int(s.size())
public: 
   // fucntion to check if all the strings in the vector are plandromes or not
   bool is_valid(vector < string > build){
       auto is_plandrome = [](string s){
           for (int i = 0; i < sz(s) / 2; i++)
              if (s[i] != s[sz(s) - i - 1])  return false;
            return true;     
        };    

       for (auto & i: build) 
         if (!is_plandrome(i)) return false;
        return true;
    }

    // vector to store the answer
    vector < vector < string > > ans;
    
    // backtraking function
    void backtraking(string s, int Idx){
        if (Idx == sz(s)){ // base case
          vector < string > build; // vector to store the current build
          // slpit the string into substrings
          for (int i = 0; i < sz(s); i++){
              string tmp;
              while (i < sz(s) && s[i] != ' ') 
               tmp += s[i++];
              build.push_back(tmp);
          }
          // check if the current build is valid or not
          if (is_valid(build))   
            ans.push_back(build);
          return;  
        }   
        // if the current character is space or the last character in the string 
        // then we don't need to cut the string
        if (s[Idx] == ' ' || (Idx == sz(s) - 1)) 
           backtraking(s, Idx + 1); // call the function with the next index
        else{
          // cut the string at the current index
          backtraking(s, Idx + 1);
          // insert space at the current index to cut the string
          s.insert(Idx + 1, " ");
          // call the function with the next of the next index 
          // because we inserted space at the current index
          backtraking(s, Idx + 2);  
          s = s.substr(0, Idx + 1) + s.substr(Idx + 2); // remove the space
        }
    }
    
    vector<vector<string>> partition(string s) {
        backtraking(s,  0); // call the backtraking function
        return ans; // return the answer
    }
};
```

<br><br>

## 23)  [Find the Town Judge](https://leetcode.com/problems/find-the-town-judge/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`Graph` `Hash Table` `Array`

### Code

```cpp
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector < int > indegree(n + 1, 0), outdegree(n + 1, 0); // indegree = incomming edges, outdegree = outgoing edges
        for(auto x: trust){ 
          // x[1] has incoming edge and x[0] has outgoing edge
            outdegree[x[0]]++;  // count outgoing edges
            indegree[x[1]]++;  // count incoming edges
        }
        for(int i = 1; i <= n; i++)
            // if indegree == n - 1 and outdegree == 0 then this is the judge 
            if(indegree[i] == n - 1 && outdegree[i] == 0) return i;
        // if no judge found return -1     
        return -1;
    }
};
```

<hr>

<br><br>

## 24)  [Snakes and Ladders](https://leetcode.com/problems/snakes-and-ladders/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Graph` `Matrix` `Breadth-First Search`

### Code
```cpp
class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        
        int lbl = 1; // label of the cell in the board
        int n = board.size();
        vector < int > columns(n); // columns of the board
        vector < pair < int, int > > cells(n * n + 1); // cells of the board
        iota(columns.begin(), columns.end(), 0); // fill the columns with 0, 1, 2, ..., n - 1
        
        // fill the cells of the board
        for (int row = n - 1; row >= 0; row--) {
            for (int column : columns) { // columns is reversed for odd rows
                cells[lbl++] = {row, column}; // label the cell with lbl and store it in cells vector
            }
            reverse(columns.begin(), columns.end()); // reverse the columns for the next row
        }

        vector < int > dist(n * n + 1, -1); // distance of each cell from the start cell
        dist[1] = 0; // distance of the start cell from itself is 0
        queue < int > q; // queue for BFS
        q.push(1); // push the start cell into the queue
 
        // BFS 
        while (!q.empty()) {
            int curr = q.front(); // current cell in the queue
            q.pop(); // pop the current cell from the queue

            // check the next 6 cells from the current cell 
            for (int next = curr + 1; next <= min(curr + 6, n * n); next++) {
                auto [row, column] = cells[next]; // get the row and column of the next cell
                // if the next cell is a snake or ladder, then go to the destination cell of the snake or ladder otherwise go to the next cell
                int destination = board[row][column] != -1 ? board[row][column] : next; 

                // if the destination cell is not visited yet, then update the distance of the destination cell and push it into the queue
                if (dist[destination] == -1) {
                    dist[destination] = dist[curr] + 1; // update the distance of the destination cell
                    q.push(destination); // push the destination cell into the queue
                }
            }
        }
        
        int ans = dist[n * n]; // distance of the last cell from the start cell 
        return ans; // return the distance of the last cell from the start cell
    }
};
```

<hr>

<br><br>

## 25)  [Find Closest Node to Given Two Nodes](https://leetcode.com/problems/find-closest-node-to-given-two-nodes/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Graph` `Breadth-First Search`

### Code

```cpp
class Solution {
public:

    vector < int > BFS(int root, vector < int >& edges){
        int n = edges.size();
        
        // save the distance form the root to each node
        vector < int > dist(n, 1e9);

        // bfs queue
        queue < int > bfs;

        // add the root to the queue and make it distance is 0
        bfs.push(root);
        dist[root] = 0;

        while(!bfs.empty()){
            int u = bfs.front();
            bfs.pop();

            // if the node has no outgoing edge
            if(edges[u] == -1) continue;

            // update the distance for the current node and add it to the queue
            int v = edges[u];
            if(dist[v] > dist[u] + 1)
                dist[v] = dist[u] + 1, bfs.push(v);
        }

        // return the distances
        return dist;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        // get distances from node1 and node2 
        vector < int > dist_a = BFS(node1, edges), dist_b = BFS(node2, edges);
        
        // get the min of max distance of all distances
        int max_dist = 1e9, node = -1;
        for(int u = 0; u < n; u++){
            // get max_dist from node1 and node2 to the node u
            int curr_dist = max(dist_a[u], dist_b[u]);

            // update the minimum distance the answer for each node
            if(curr_dist < max_dist)
                max_dist = curr_dist, node = u;
        }

        // the index of the node that can be reach to the two nodes with minimum distance
        return node;
    }
};
```


<hr>

<br><br>

## 26)  [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Dynamic Programming` `Depth-First Search` `Breadth-First Search` `Graph` `Heap (Priority Queue)` `Shortest Path`

### Code


```cpp
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector < vector < int > > dp(k + 2, vector < int >(n, INT_MAX));

        for (int i = 0; i <= k + 1; i++) 
            dp[i][src] = 0; 

        for (int i = 1; i <= k + 1; i++) {
            for (const auto& f : flights) {
                if (dp[i - 1][f[0]] != INT_MAX) {
                    dp[i][f[1]] = min(dp[i][f[1]], dp[i - 1][f[0]] + f[2]);
                }
            }
        }
        return dp[k + 1][dst] == INT_MAX ? -1 : dp[k + 1][dst];
    }
};
```

<hr>

<br><br>

## 27)  [Concatenated Words](https://leetcode.com/problems/concatenated-words/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Dynamic Programming` `Depth-First Search` `Array` `String` `Trie`

### Code


```cpp
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        vector < string > res; // answer vector
        unordered_set < string > words_set; // set of words 
        for (string word : words) words_set.insert(word); // insert all words in set
    
        for (string word : words) {
            
            int n = word.size();
            vector < int > dp(n + 1, 0); // dp[i] = 1 if we can make word[0..i] from words in set
            dp[0] = 1; // empty string is always in set

            for (int i = 0; i < n; i++) {
                if (!dp[i]) continue; // if we can't make word[0..i] then we can't make word[0..n]
                for (int j = i + 1; j <= n; j++)  // try to make word[0..j] from word[0..i] and word[i..j]
                    // if word[i..j] is in set and we can make word[0..i] then we can make word[0..j]
                    if (j - i < n && words_set.count(word.substr(i, j - i))) 
                        dp[j] = 1; // mark word[0..j] as valid
                
                // if we can make word[0..n] then we can make word from words in set
                if (dp[n]) {
                    res.push_back(word); // add word to answer
                    break; // no need to check other words
                }
            }
        }
        return res; // return answer
    }
};
```

<hr>

<br><br>

## 28)  [Data Stream as Disjoint Intervals](https://leetcode.com/problems/data-stream-as-disjoint-intervals/)

### Difficulty

**${\bf{\color\{red}\{Hard}}}$**

### Related Topic

`Binary Search` `Design` `Ordered Set`

### Code


```cpp
class SummaryRanges {

#define sz(s) int(s.size())
#define all(s) s.begin(), s.end()

vector < int > v; 
unordered_map < int, bool > mp;

public:
    // add number to the data structure
    void addNum(int value) {
        if(!(mp.count(value))) { // if value not exist in the data structure
          v.insert(upper_bound(all(v), value), value); // insert value in the sorted vector
          mp[value] = true;  // mark value as exist in the data structure
        }
    }
    
     vector < vector < int > > getIntervals() {
        // the answer is the vector of the intervals
        vector < vector < int > > ans = {{v[0]}};  // the first interval is the first element in the vector

        // loop on the vector and check if the current element is the next element in the last interval
        for(int i = 1; i < sz(v); i++){
            if(ans.back().back() + 1 == v[i]) {  // if the current element is the next element in the last interval
                if(sz(ans.back()) == 2) ans.back().back() = v[i];  // if the last interval has two elements, update the last element
                else ans.back().push_back(v[i]);  // if the last interval has one element, add the current element to the last interval
            }
            // if the current element is not the next element in the last interval
            else {
                if(sz(ans.back()) == 1) // if the last interval has one element, add the first element to the last interval
                  ans.back().emplace_back(ans.back()[0]); // add the first element to the last interval 
                ans.push_back({v[i]});  // add new interval with the current element
            }
        }
        // if the last interval has one element, add the first element to the last interval
        if(sz(ans.back()) == 1)
          // add the first element to the last interval
           ans.back().emplace_back(ans.back()[0]); 

        return ans; // return the answer
    }
};
```


<hr>

<br><br>

## 29)  [LFU Cache](https://leetcode.com/problems/lfu-cache/)

### Difficulty

**${\bf{\color\{red}\{Hard}}}$**

### Related Topic

`Hash Table` `Linked List` `Design` `Doubly-Linked List`

### Code

```cpp
class LFUCache {
    int maxSizeCache; // maximum capacity of the cache
    int size; // current number of elements in the cache
    int minFreq; // the minimum frequency of elements in the cache
    unordered_map<int, pair<int, int>> keyNode; // key to {value,freq}
    unordered_map<int, list<int>::iterator> keylist; // key to list iterator
    unordered_map<int, list<int>>  freqKeyLt;  // freq to key list
public:
    LFUCache(int capacity) {
        maxSizeCache = capacity; // setting the maximum capacity of the cache
        size = 0; // initially the size is zero
    }
    
    int get(int key) {
        // if the key is not in the cache, return -1
        if(keyNode.count(key) == 0) return -1;
        
        // remove the key from its current frequency list
        freqKeyLt[keyNode[key].second].erase(keylist[key]);
        
        // increase the frequency of the key
        keyNode[key].second++;
        
        // add the key to the frequency list with its new frequency
        freqKeyLt[keyNode[key].second].push_back(key);
        
        // update the key's position in the keylist
        keylist[key]= --freqKeyLt[keyNode[key].second].end();
        
        // if the list of minimum frequency is empty, update the minimum frequency
        if(freqKeyLt[minFreq].size()==0 ) 
              minFreq++;
        
        // return the value associated with the key
        return keyNode[key].first;
    }
    
   void put(int key, int value) {
        // if the cache has a maximum capacity of 0, return
        if(maxSizeCache <= 0) return;
        
        // check if the key already exists in the cache
        int storedValue = get(key);
        if(~storedValue){
            // if the key already exists, update its value
            keyNode[key].first=value;
            return;
        }
        
        // if the cache is full, remove the least frequently used key
        if(size >= maxSizeCache){
            keyNode.erase(freqKeyLt[minFreq].front());
            keylist.erase(freqKeyLt[minFreq].front());
            freqKeyLt[minFreq].pop_front();
            size--;
        }
        
        // add the new key to the cache
        keyNode[key] = {value, 1};
        freqKeyLt[1].push_back(key);
        keylist[key]= --freqKeyLt[1].end();
        minFreq = 1;
        size++;
    }
};
```

<hr>

<br><br>

## 30)  [N-th Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`Dynamic Programming` `Memoization` `Math` 

### Code

```cpp
class Solution {
public:
    int dp[45]; // dp array to store the result of the subproblems
    int Tribonacci(int n){ 
      // base case 
      if (n <= 2) return 0 + (n > 0);
      // if the result is already computed, return it
      int &ret = dp[n]; 
      if (~ret) return ret;
      // recursive case to compute the result of the subproblems and store it in the dp array 
      return ret = Tribonacci(n - 1) + Tribonacci(n - 2) + Tribonacci(n - 3);
    }
    
    int tribonacci(int n) {
         memset(dp, -1, sizeof(dp)); // initialize the dp array with -1
         return Tribonacci(n); // call the recursive function
    }
};
```


<hr>

<br><br>

## 31)  [Best Team With No Conflicts](https://leetcode.com/problems/best-team-with-no-conflicts/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Dynamic Programming` `Array` `Sorting` 

### Code

```cpp
class Solution {
#define sz(s) int(s.size()) 
#define ll long long
#define all(s) s.begin(), s.end()
public:
  ll dp[1005][1005]; // dp[Idx][prve] = max score if we take the idx and the previous idx is prve
  vector < pair < ll, ll > > build; // build[i] = {age, score}
  // we will sort the build vector by age and then we will try to take the idx and the previous idx
  ll get_max(int Idx, ll prve){
    if(Idx == sz(build) - 1) return 0; // if we reach the end of the vector
    // if we take the idx and the previous idx is prve
    ll &ret = dp[Idx][prve]; 
    if(~ret) return ret;
    ret = 0; // if we don't take the idx
    // if the age of the idx is greater than the age of the previous idx then we can take the idx
    if(build[Idx].second >= build[prve].second) 
      ret = max(ret, build[Idx].second + get_max(Idx + 1, Idx)); // take the idx
    ret = max(ret, get_max(Idx + 1, prve)); // don't take the idx
    return ret; // return the maximum
  }

  int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    ll n = sz(scores);
    build = vector < pair < ll, ll > > (n); // build[i] = {age, score}
    for(int i = 0; i < n; i++) build[i] = {ages[i], scores[i]}; 
    sort(all(build)); // sort the build vector by age 
    build.push_back({-10, -10}); // add a dummy element to the end of the vector
    memset(dp, -1, sizeof dp); // initialize the dp array with -1
    return get_max(0, n); // return the maximum score
  }
};
```
