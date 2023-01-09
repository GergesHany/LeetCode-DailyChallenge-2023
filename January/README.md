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

