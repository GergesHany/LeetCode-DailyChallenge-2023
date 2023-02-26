LeetCode Daily Challenge Problems for February

## Problems:

1. **[Greatest Common Divisor of Strings](#1--greatest-common-divisor-of-strings)**
1. **[Verifying an Alien Dictionary](#2--verifying-an-alien-dictionary)**
1. **[Zigzag Conversion](#3--zigzag-conversion)**
1. **[Permutation in String](#4--permutation-in-string)**
1. **[Find All Anagrams in a String](#5--find-all-anagrams-in-a-string)**
1. **[Shuffle the Array](#6--shuffle-the-array)**
1. **[Fruit Into Baskets](#7--fruit-into-baskets)**
1. **[Jump Game II](#8--jump-game-ii)**
1. **[Naming a Company](#9--naming-a-company)**
1. **[As Far from Land as Possible](#10--as-far-from-land-as-possible)**
1. **[Shortest Path with Alternating Colors](#11--shortest-path-with-alternating-colors)**
1. **[Minimum Fuel Cost to Report to the Capital](#12--minimum-fuel-cost-to-report-to-the-capital)**
1. **[Count Odd Numbers in an Interval Range](#13--count-odd-numbers-in-an-interval-range)**
1. **[Add Binary](#14--add-binary)**
1. **[Add to Array-Form of Integer](#15--add-to-array-form-of-integer)**
1. **[Maximum Depth of Binary Tree](#16--maximum-depth-of-binary-tree)**
1. **[Minimum Distance Between BST Nodes](#17--minimum-distance-between-bst-nodes)**
1. **[Invert Binary Tree](#18--invert-binary-tree)**
1. **[Binary Tree Zigzag Level Order Traversal](#19--Binary-Tree-Zigzag-Level-Order-Traversal)**
1. **[Search Insert Position](#20--Search-Insert-Position)**
1. **[Single Element in a Sorted Array](#21--single-element-in-a-sorted-array)**
1. **[Capacity To Ship Packages Within D Days](#22--capacity-to-ship-packages-within-d-days)**
1. **[IPO](#23--ipo)**
1. **[Minimize Deviation in Array](#24--minimize-deviation-in-array)**
1. **[Best Time to Buy and Sell Stock](#25--best-time-to-buy-and-sell-stock)**
1. **[Edit Distance](#26--Edit-Distance)**

<hr>

<br><br>

## 1)  [Greatest Common Divisor of Strings](https://leetcode.com/problems/greatest-common-divisor-of-strings/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`String` `Math`

### Code


```cpp
class Solution {
#define sz(s) int(s.size())
public:
    // check if s is valid string to be repeated to get t
    bool is_valid(string s, string t){
       string temp = s;
        while(sz(temp) < sz(t)) // repeat s until it's length is greater than t
            temp += s; // repeat s 
        return temp == t; // check if temp is equal to t
    }
    string gcdOfStrings(string str1, string str2) {
      string ans = ""; 
        for (int i = 0; i < sz(str1); i++) {
            string temp = str1.substr(0, i + 1); // get the prefix of str1
            if (is_valid(temp, str1) && is_valid(temp, str2)){ // check if temp is valid string to be repeated to get str1 and str2
                if (sz(temp) >= sz(ans)) // get the longest valid string
                    ans = temp; // update the answer
            }
        }
        return ans; // return the answer
    }
};
```

<hr>

<br><br>

## 2)  [Verifying an Alien Dictionary](https://leetcode.com/problems/verifying-an-alien-dictionary/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`String` `Array`  `Hash Table`

### Code

```cpp
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int j = 0;
        map < char, int > mp;
        for(auto &it : order) mp[it] = j++; // map each char to its index in the order string

        for(int i = 1; i < words.size(); i++){

            bool flag = false; // flag to check if the first string is smaller than the second string  
            string first = words[i - 1]; // first string
            string second = words[i]; // second string

            int minLen = min(first.size(), second.size()); // get the minimum length of the two strings

            for(int j = 0; j < minLen; j++){
                // if the first string is smaller than the second string
                if(mp[first[j]] < mp[second[j]]) {
                    flag = true; // set the flag to true 
                    break; // break the loop
                }

                if(mp[first[j]] > mp[second[j]]) return false; // if the first string is greater than the second string return false
            }
            if(!flag && first.size() > second.size()) return false; // if the flag is false and the first string is greater than the second string return false
        }
        return true; // return true if all the strings are sorted
    }
};
```

<hr>

<br><br>

## 3)  [Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`String`

### Code


```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        if(numRows == 1) return s; // if numRows == 1, return s directly
        int n = s.size(); // get the size of s
        int cycle = 2 * numRows - 2; // get the cycle of the zigzag pattern
        for(int i = 0; i < numRows; i++){ // loop over the rows
            for(int j = 0; j + i < n; j += cycle){ // loop over the columns
                ans += s[j + i]; // add the character in the current row
                // add the character in the middle of two adjacent rows if it exists 
                if(i != 0 && i != numRows - 1 && j + cycle - i < n){ 
                    ans += s[j + cycle - i];
                }
            }
        }
        return ans; // return the answer
    }
};
```
<hr>

<br><br>

## 4)  [Permutation in String](https://leetcode.com/problems/permutation-in-string/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Hash Table` `Two Pointers` `String` `Sliding Window`

### Code


```cpp
class Solution {
#define sz(s) int(s.size())
#define all(s) s.begin(), s.end()
public:
    bool checkInclusion(string s1, string s2) {
        int n = sz(s1), m = sz(s2); 
        if (n > m) return false; // s1 is bigger than s2 so it can't be a permutation of s2
        vector < int > cnt1(26), cnt2(26); // count of each character in s1 and s2
        for (int i = 0; i < n; i++) {
            cnt1[s1[i] - 'a']++; // count of each character in s1
            cnt2[s2[i] - 'a']++; // count of each character in s2
        }
        // sliding window technique to check if s1 is a permutation of s2
        for (int i = n; i < m; i++) {
            if (cnt1 == cnt2) return true; // if the count of each character in s1 and s2 is the same then s1 is a permutation of s2
            cnt2[s2[i] - 'a']++; // add the new character to the count of s2
            cnt2[s2[i - n] - 'a']--; // remove the first character from the count of s2
        }
        return cnt1 == cnt2;  // check if the last window is a permutation of s1       
    }
};
```
<hr>

<br><br>

## 5)  [Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Hash Table` `String` `Sliding Window`

### Code


```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      vector < int > ans;
      int n = s.size(), m = p.size();
      if (n < m) return ans; // if the size of the string is less than the size of the pattern
      vector < int > cnt(26); // count the frequency of each character in the pattern
      for (char c : p) cnt[c - 'a']++; // count the frequency of each character in the pattern
      for (int i = 0; i < m; i++) cnt[s[i] - 'a']--; // count the frequency of each character in the string
      bool ok = true; // check if the frequency of each character in the string is equal to the frequency of each character in the pattern
      for (int i = 0; i < 26; i++) if (cnt[i]) ok = false; // check if the frequency of each character in the string is equal to the frequency of each character in the pattern
      if (ok) ans.push_back(0); // if the frequency of each character in the string is equal to the frequency of each character in the pattern
      for (int i = m; i < n; i++) { // slide the window over the string
        cnt[s[i] - 'a']--; // minus the frequency of the last character in the string
        cnt[s[i - m] - 'a']++; // count the frequency of each character in the string
        ok = true; // check if the frequency of each character in the string is equal to the frequency of each character in the pattern
        for (int i = 0; i < 26; i++) if (cnt[i]) ok = false; // check if the frequency of each character in the string is equal to the frequency of each character in the pattern
        if (ok) ans.push_back(i - m + 1); // if the frequency of each character in the string is equal to the frequency of each character in the pattern
      }
      return ans; // return the answer
    }
};
```

<hr>

<br><br>

## 6)  [Shuffle the Array](https://leetcode.com/problems/shuffle-the-array/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`Array`

### Code


```cpp
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector < int > ans; // vector to store the answer
        for (int i = 0; i < n; i++) 
          ans.push_back(nums[i]), ans.push_back(nums[i + n]); // push the first half of the array then the second half
        return ans; // return the answer   
    }
};
```

<hr>

<br><br>

## 7)  [Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Array` `Hash Table` `Sliding Window`

### Code


```cpp
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       int ans = 0;
       map < int, int > freq; // freq of each fruit
       int cnt_diff = 0; // number of different fruits
       // [L, R] is the current window of fruits
       int L = 0, R = 0, n = fruits.size();  
       // R is the right pointer of the window
       while(R < n && L < n){
          freq[fruits[R]]++; // add the new fruit
          if (freq[fruits[R]] == 1) cnt_diff++; // if it's a new fruit then increase the number of different fruits
          if (cnt_diff <= 2){ // if the number of different fruits is less than or equal to 2 then we can add the new fruit
            ans = max(ans, R - L + 1); // update the answer
          }
          else{
            while(L < R && cnt_diff > 2){ // if the number of different fruits is greater than 2 then we need to remove the leftmost fruit
              freq[fruits[L]]--; // remove the leftmost fruit
              if (!freq[fruits[L]]) cnt_diff--; // if the leftmost fruit is the last one then decrease the number of different fruits
              L++; // move the left pointer to the right
            }
          }
          R++; // move the right pointer to the right
       }      
       return ans; // return the answer 
    }
};
```
<hr>

<br><br>

## 8)  [Jump Game II](https://leetcode.com/problems/jump-game-ii/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Array` `Dynamic Programming` `Greedy`

### Code


```cpp
class Solution {
#define sz(s) int(s.size())
public:
    vector < int > num, dp;
    // dp[i] = min number of jumps to reach the end from i
    int get_min(int Idx){
       // base case 
       if (Idx >= sz(num) - 1) 
         return Idx == sz(num) - 1 ? 0 : 1e9; // if we are at the end return 0 else return 1e9
      
      // memoization
      int & ret = dp[Idx]; // current state
      if (~ret) return ret; // if we have already calculated the answer return it
      ret = 1e9; // initialize the answer with 1e9

      // transition 
      for (int i = 1; i <= num[Idx]; i++) 
        ret = min(ret, 1 + get_min(Idx + i));

      return ret; // return the answer  
    }

    int jump(vector<int>& nums) {
      num = nums; // copy the array
      dp.assign(sz(nums) + 10, -1); // initialize the dp array with -1
      return get_min(0); // call the function
    }
};
```

<hr>

<br><br>

## 9)  [Naming a Company](https://leetcode.com/problems/naming-a-company/)

### Difficulty

**${\bf{\color\{red}\{Hard}}}$**

### Related Topic

`Array` `Hash Table` `String` `Bit Manipulation` `Enumeration`

### Code


```cpp
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int ans = 0; 
        vector < unordered_set < string > > words(26); // 26 letters in the alphabet 
        for (auto & i: ideas) 
           words[i[0] - 'a'].insert(i.substr(1)); // insert the word without the first letter
        
        // for each pair of words, we count the number of distinct letters in the two words 
        for (int i = 0; i < 25; i++){
            // for each word, we count the number of distinct letters in the word
            for (int j = i + 1; j < 26; j++){
                // we count the number of distinct letters in the two words
                unordered_set < string > st; // set of distinct letters in the two words
                st.insert(words[i].begin(), words[i].end()); // insert the letters of the first word
                st.insert(words[j].begin(), words[j].end());  // insert the letters of the second word
                // we count the number of distinct letters in the two words 
                ans += (int(words[j].size()) - int(st.size())) * (int(words[i].size()) - int(st.size()));
            }
        }
        return 1LL * ans * 2; // we multiply by 2 because we counted each pair twice
    }
};
```

<hr>

<br><br>

## 10)  [As Far from Land as Possible](https://leetcode.com/problems/as-far-from-land-as-possible/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Array` `Dynamic Programming` `Breadth-First Search` `Matrix`

### Code


```cpp
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
```
<hr>

<br><br>

## 11)  [Shortest Path with Alternating Colors](https://leetcode.com/problems/shortest-path-with-alternating-colors/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Graph` `Breadth-First Search`

### Code


```cpp
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n); // node, color
        for (auto& redEdge : redEdges) 
            adj[redEdge[0]].push_back({redEdge[1], 0}); // 0 for red
        
        for (auto& blueEdge : blueEdges) 
            adj[blueEdge[0]].push_back(make_pair(blueEdge[1], 1)); // 1 for blue

        vector<int> answer(n, -1); // -1 for not visited
        vector<vector<bool>> visit(n, vector<bool>(2)); // 2 for red and blue
        queue<vector<int>> q; // node, steps, prevColor

        q.push({0, 0, -1}); // 0 for node, 0 for steps, -1 for prevColor
        visit[0][1] = visit[0][0] = true, answer[0] = 0; // 0 for red and blue and 0 for steps for node 0 

        while (!q.empty()) {
            auto element = q.front(); // node, steps, prevColor
            int node = element[0]; // node
            int steps = element[1], prevColor = element[2]; // steps, prevColor
            q.pop(); // remove the first element

            // if the node is visited with the same color, then continue
            for (auto& [neighbor, color] : adj[node]) {
                // if the neighbor is not visited with the same color, then push it to the queue
                if (!visit[neighbor][color] && color != prevColor) {
                    visit[neighbor][color] = true; // mark the neighbor as visited with the same color
                    q.push({neighbor, 1 + steps, color}); // push the neighbor to the queue
                    if (answer[neighbor] == -1) answer[neighbor] = 1 + steps; // if the neighbor is not visited before, then update the answer
                }
            }
        }
        return answer; // return the answer
    }
};
```

<hr>

<br><br>


## 12)  [Minimum Fuel Cost to Report to the Capital](https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Tree` `Depth-First Search` `Breadth-First Search` `Graph`

### Code


```cpp
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
```

<hr>

<br><br>


## 13)  [Count Odd Numbers in an Interval Range](https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`Math`

### Code


```cpp
class Solution {
public:
    // number of even numbers between a and b
    int get_even(int a, int b){
      return (b / 2) - ((a - 1) / 2);
    }

    // number of odd numbers between a and b
    int get_odd(int a, int b){
      return ((b - a) + 1) - get_even(a, b) - (a == 0);
    }

    int countOdds(int low, int high) {
       return get_odd(low, high);
    }
};
```
<hr>

<br><br>


## 14)  [Add Binary](https://leetcode.com/problems/add-binary/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`Math` `String` `Bit Manipulation` `Simulation`

### Code


```cpp
#define sz(s) s.size()
class Solution {
public:
    
    string add_Binary(string a, string b) {
    string result = ""; // Initialize result
    int s = 0;          // Initialize digit sum
 
    // Traverse both strings starting from last
    // characters
    int i = sz(a) - 1, j = sz(b) - 1;
    while (i >= 0 || j >= 0 || s == 1){
        // Comput sum of last digits and carry
        s += ((i >= 0) ? a[i] - '0': 0);
        s += ((j >= 0) ? b[j] - '0': 0);
 
        // If current digit sum is 1 or 3, add 1 to result
        result = char(s % 2 + '0') + result;
 
        // Compute carry
        s /= 2;
 
        // Move to next digits
        i--; j--;
    }
    return result;
   }

    
    string addBinary(string a, string b) {
        return add_Binary(a, b);
    }
};
```
<hr>

<br><br>


## 15)  [Add to Array-Form of Integer](https://leetcode.com/problems/add-to-array-form-of-integer/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`Math` `Array`

### Code


```cpp
class Solution {
public:
    string BigAdd(string s, string t){
        string res;
        int sz = max(s.size(), t.size());
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        char carry = '0';
        int e = 0, f = 0;
        for(int i = 0; i < sz || carry != '0'; i++){
          e = (i >= s.size() ? 0 : s[i] - '0');
          f = (i >= t.size() ? 0 : t[i] - '0');
          int tmp = (carry - '0') + e + f;
          carry = (tmp / 10) + '0';
          res.push_back(tmp % 10 + '0');
        }
        reverse(res.begin(), res.end());
        while(res[0] == '0') res.erase(res.begin());
        return res;
    }

    vector<int> addToArrayForm(vector<int>& num, int k) {
        string number;
        for (auto & i: num)
           number += to_string(i);
        
        string temp = BigAdd(number, to_string(k));
        vector < int > ans(int(temp.size()));
        
        for (int i = 0; i < int(temp.size()); i++){
            ans[i] = temp[i] - '0'; 
        }     

        return ans;
    }
};
```
<hr>

<br><br>


## 16)  [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

### Code


```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // if the root is null i will return 0
        // otherwise i will return 1 + max depth of my left and right children depth
        return (!root ? 0 : 1 + max(maxDepth(root -> right), maxDepth(root -> left)));
    }
};
```

## 17)  [Minimum Distance Between BST Nodes](https://leetcode.com/problems/minimum-distance-between-bst-nodes/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree` `Binary Search Tree`

### Code


```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
       int ans = INT_MAX;
       vector < int > build;
        auto dfs = [&](auto dfs, TreeNode* root) -> void {
            if(!root) return;
            build.push_back(root->val);
            dfs(dfs, root->left);
            dfs(dfs, root->right);
        };
        dfs(dfs, root);
        sort(build.begin(), build.end());
        for(int i = 1; i < build.size(); i++)
            ans = min(ans, build[i] - build[i - 1]);
        return ans; 
    }
};
```

## 18)  [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

### Code


```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL; // base case
        TreeNode* left = invertTree(root->left); // invert left subtree
        TreeNode* right = invertTree(root->right); // invert right subtree
        root->left = right; // swap left and right subtrees
        root->right = left; // swap left and right subtrees
        return root;
    }
};
```


## 19)  [Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Tree` `Breadth-First Search` `Binary Tree`

### Code


```cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
#define sz(s) int(s.size())
#define all(s) s.begin(), s.end()
public:
    // function to do dfs and push the nodes in the vector
    void dfs(TreeNode* root, int level, vector < vector < int > > &ans){
      if (!root) return; // if the node is null return
      if (sz(ans) == level) ans.push_back({}); // if the level is not in the vector push it
      ans[level].push_back(root->val); // push the node in the vector
      dfs(root->left, level + 1, ans); // do dfs in the left subtree
      dfs(root->right, level + 1, ans); // do dfs in the right subtree
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector < vector < int > > ans; // vector to store the answer
      if (!root) return ans; // if the root is null return the vector
      dfs(root, 0, ans); // do dfs and push the nodes in the vector
      // reverse the odd levels in the vector to get the zigzag order
      for (int i = 1; i < sz(ans); i += 2) 
        reverse(all(ans[i])); 
      return ans;  // return the vector 
    }
};
```


## 20)  [Search Insert Position](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`Array` `Binary search` 

### Code


```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      // initalize the index with the size of the vector because if the target is greater than all the elements in the vector then the index will be the size of the vector
        int Idx = int(nums.size()); 
        int l = 0, r =  int(nums.size()) - 1; // l = left, r = right
        // binary search
        while(l <= r){
            long long mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) r = mid - 1;
            else l = mid + 1, Idx = mid + 1;
        }  
        if (nums[0] > target) Idx = 0; // if the target is less than the first element in the vector then the index will be 0
        return Idx; // return the index
    }
};
```


## 21)  [Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`Array` `Binary Search`

### Code


```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0; // 0 ^ x = x and x ^ x = 0
        // so we can xor all the elements and the result will be the single element 
        // because all the other elements will be paired with it 
        // and the xor of two equal elements will be 0 
        for (auto x : nums) ans ^= x;  // find the single element
        return ans; // return the single element
    }
};
```
<hr>

<br><br>

## 22)  [Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Array` `Binary Search`

### Code


```cpp
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size(); // number of weights
        int l = *max_element(weights.begin(), weights.end()); // min capacity
        long long r = accumulate(weights.begin(), weights.end(), 0LL); // max capacity
        // binary search on the answer
        while(l < r){
            int sum = 0, cnt = 1; // cnt is the number of days needed
            long long mid = l + (r - l) / 2; // mid is the capacity of the ship
            // check if we can ship all the weights in mid days
            for(int i = 0; i < n; i++){
                // if the current weight is greater than the capacity of the ship then we can't ship it
                if(sum + weights[i] > mid){
                    cnt++, sum = 0; // we need another day to ship the current weight
                }
                sum += weights[i]; // add the current weight to the sum
            }
            // if the number of days needed is greater than the given days then we need to increase the capacity of the ship
            if(cnt > days) l = mid + 1;
            else r = mid; // else we can decrease the capacity of the ship
        }
        return l; // return the minimum capacity of the ship
    }
};
```

<hr>

<br><br>

## 23)  [IPO](https://leetcode.com/problems/ipo/)

### Difficulty

**${\bf{\color\{red}\{Hard}}}$**

### Related Topic

`Array` `Greedy` `Sorting` `Heap (Priority Queue)`

### Code


```cpp
class Solution {
#define all(s)  s.begin(),  s.end()
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {   
      int Idx = 0; // index of projects 
      int n = profits.size(); // number of projects
      priority_queue< pair < int, int > > pq; // max heap
      vector < pair < int, int > > projects(n); // pair of capital and profit
      // store capital and profit in vector of pairs
      for(int i = 0; i < n; i++)
        projects[i] = {capital[i], profits[i]}; 

      sort(all(projects)); // sort projects by capital 

      int ans = w; // current capital
      while(k--){
        // add all projects that can be done with current capital
        while(Idx < n && projects[Idx].first <= ans)
          pq.push({projects[Idx].second, projects[Idx].first}), Idx++;
        if(pq.empty()) break; // no more projects can be done
        ans += pq.top().first; // add profit of project with max profit
        pq.pop(); // remove project with max profit
      }
      return ans; // return current capital
    }
};
```


<hr>

<br><br>

## 24)  [Minimize Deviation in Array](https://leetcode.com/problems/minimize-deviation-in-array/)

### Difficulty

**${\bf{\color\{red}\{Hard}}}$**

### Related Topic

`Array` `Greedy` `Ordered Set` `Heap (Priority Queue)`

### Code


```cpp
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int Min = INT_MAX;  // min value in the heap
        priority_queue<int> pq; // max heap 
        for (int num : nums) {
            // make all numbers even 
            if (num & 1)  num *= 2;
            // insert all numbers in the heap
            pq.push(num);
            // update the min value
            Min = min(Min, num);
        }

        int ans = 1e9; // the answer
        while (true) {
            int maxVal = pq.top(); // the max value in the heap
            pq.pop(); // remove it
            ans = min(ans, maxVal - Min); // update the answer
            if (maxVal & 1) break; // if the max value is odd then break
            maxVal = maxVal / 2; // make it even
            Min = min(Min, maxVal); // update the min value
            pq.push(maxVal); // insert it in the heap
        }
        return ans; // return the answer
    }
};
```

<hr>

<br><br>

## 25)  [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`Array` `Dynamic Programming`

### Code


```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int ans = 0, minn = 1e9; // 1e9 is the maximum value of prices[i]
      for(int i = 0; i < prices.size(); i++){
        // minn is the minimum value of prices[i] before prices[i]
        if(prices[i] < minn){
          minn = prices[i];
        }
        // ans is the maximum value of prices[i] - minn
        if(prices[i] - minn > ans){
          ans = prices[i] - minn;
        }
      }
      return ans; // return the maximum value of prices[i] - minn
    }
};
```

## 26)  [Edit Distance](https://leetcode.com/problems/edit-distance/)

### Difficulty

**${\bf{\color\{red}\{Hard}}}$**

### Related Topic

`String` `Dynamic Programming`

### Code


```cpp
class Solution {
#define sz(s) int(s.size())
#define ll long long
public:
    string s, t; // s = word1, t = word2
    ll dp[505][505]; // dp[i][j] = min cost to convert s[i..] to t[j..]

    // get_min_cost(i, j) = min cost to convert s[i..] to t[j..]
    ll get_min_cost(int i, int j){
        // base case
        if (i == sz(s)) // s is empty so we need to insert all chars in t
          return sz(t) - j;

        if (j == sz(t)) // t is empty so we need to delete all chars in s
          return sz(s) - i;

        // memoization
        ll &ret = dp[i][j];
        if (~ret) return ret; 
 
        // recursive case

        if (s[i] == t[j]) // no need to do anything
          ret = get_min_cost(i + 1, j + 1);
        
        else{
          // insert
          ret = 1 + get_min_cost(i, j + 1);
          // delete
          ret = min(ret, 1 + get_min_cost(i + 1, j));
          // replace
          ret = min(ret, 1 + get_min_cost(i + 1, j + 1));
        }
        
        return ret; // return the min cost
    }

    int minDistance(string word1, string word2) {
        s = word1, t = word2; // s = word1, t = word2
        memset(dp, -1, sizeof(dp)); // initialize dp with -1
        return get_min_cost(0, 0); // return the min cost to convert s to t
    }
};

```

