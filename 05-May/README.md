## LeetCode Daily Challenge Problems for May

## Problems:

1. **[Average Salary Excluding the Minimum and Maximum Salary](#1--Average-Salary-Excluding-the-Minimum-and-Maximum-Salary)**
1. **[Sign of the Product of an Array](#2--Sign-of-the-Product-of-an-Array)**
1. **[Find the Difference of Two Arrays](#3--Find-the-Difference-of-Two-Arrays)**
1. **[Dota2 Senate](#4--Dota2-Senate)**
1. **[Maximum Number of Vowels in a Substring of Given Length](#5--Maximum-Number-of-Vowels-in-a-Substring-of-Given-Length)**
1. **[Number of Subsequences That Satisfy the Given Sum Condition](#6--Number-of-Subsequences-That-Satisfy-the-Given-Sum-Condition)**
1. **[Find the Longest Valid Obstacle Course at Each Position](#7--Find-the-Longest-Valid-Obstacle-Course-at-Each-Position)**
1. **[Matrix Diagonal Sum](#8--Matrix-Diagonal-Sum)**
1. **[Spiral Matrix](#9--Spiral-Matrix)**
1. **[Spiral Matrix II](#10--Spiral-Matrix-II)**
1. **[Uncrossed Lines](#11--Uncrossed-Lines)**
1. **[Solving Questions With Brainpower](#12--Solving-Questions-With-Brainpower)**
1. **[Count Ways To Build Good Strings](#13--Count-Ways-To-Build-Good-Strings)**
1. **[Maximize Score After N Operations](#14--Maximize-Score-After-N-Operations)**


<hr>

<br><br>

## 1)  [Average Salary Excluding the Minimum and Maximum Salary](https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/)

### Difficulty

**${\bf{\color\{green}{Easy}}}$**

### Related Topic

`sorting` `array`

### Code


```cpp
class Solution {
public:
    double average(vector<int>& salary) {

       long double sum = 0; // sum of all salaries except min and max

       int mn = *min_element(salary.begin(), salary.end()); // min salary
       int mx = *max_element(salary.begin(), salary.end()); // max salary
       
       int sz = 0; // size of salary vector except min and max
       for (auto & i: salary)
        // if salary is not min and max then add it to sum and increase size
         if (i != mn && i != mx) 
            sum += i, sz++;   
        // return average    
       return sum / double(sz);      
    }
};
```

<hr>

<br><br>

## 2)  [Sign of the Product of an Array](https://leetcode.com/problems/sign-of-the-product-of-an-array/)
### Difficulty

**${\bf{\color\{green}{Easy}}}$**

### Related Topic

`Array` `Math`

### Code
```cpp
class Solution {
public:
    int arraySign(vector<int>& nums) {
       int neg = 0; // count the number of negative numbers
       for (auto & i: nums){
           // if there is a zero, return 0 immediately 
           // because the product will be zero 
           if (!i) return 0; 
           // count the number of negative numbers
           neg += (i < 0);
       }  
       // if the number of negative numbers is odd, 
       // the product will be negative 
       // otherwise, the product will be positive
       return (neg & 1 ? -1 : 1);
    }
};
```
<br><hr>

## 3)  [Find the Difference of Two Arrays](https://leetcode.com/problems/find-the-difference-of-two-arrays/)

### Difficulty

**${\bf{\color\{green}{Easy}}}$**

### Related Topic

`Array` `Hash Table`

### Code
```cpp
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // map to count the frequency of each element
        map < int, int > a, b; 

        // count the frequency of each element in nums1 and nums2
        for (auto & i: nums1) a[i]++;
        for (auto & i: nums2) b[i]++;
        
        vector < int > A, B; // A: elements in nums1 but not in nums2, B: elements in nums2 but not in nums1
        // find the elements in nums1 but not in nums2
        for (auto & i: nums1) if (!b[i]) B.push_back(i), b[i] = 1;
        // find the elements in nums2 but not in nums1
        for (auto & i: nums2) if (!a[i]) A.push_back(i), a[i] = 1;
        // the answer is the union of A and B
        vector < vector < int > > ans = {B, A};
        // return the answer
        return ans; 
    }
};
```

<hr><br>

## 4)  [Dota2 Senate](https://leetcode.com/problems/dota2-senate/)

### Difficulty

**${\bf{\color\{green}{Medium}}}$**

### Related Topic

`String` `Greedy` `Queue`

### Code
```cpp
class Solution {
public:
    string predictPartyVictory(string senate) {
        
        int score = 0; 
        for (int i = 0; i < senate.size(); ++i) {
            const char ch = senate[i];
            if (ch == 'R') {
                if (score < 0) 
                    senate.push_back('D');
                ++score;
            } else {
                if (score > 0) 
                    senate.push_back('R');
                --score;
            }
        }
        return (score > 0 ? "Radiant" : "Dire");
   }
};
```

<hr><br>



## 5)  [Maximum Number of Vowels in a Substring of Given Length](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/)

### Difficulty

**${\bf{\color\{green}{Medium}}}$**

### Related Topic

`String` `Sliding Window`

### Code
```cpp
class Solution {
public:
    int maxVowels(string s, int k) {      
        string Vowels = "aeiou"; // the string of vowels

        // sliding window technique
        int ans = 0, l = 0, r = 0, cnt = 0;
        while(r < k) { 
            // count the number of vowels in the first window
            cnt += (Vowels.find(s[r]) != -1);
            r++;
        }        

        ans = cnt; // update the answer
        // sliding the window to the right and update the answer
        while(r < int(s.size())){
            cnt += (Vowels.find(s[r++]) != -1);
            cnt -= (Vowels.find(s[l++]) != -1);
            ans = max(ans, cnt);
        }
        return ans;
    }
};
```

## 6)  [Number of Subsequences That Satisfy the Given Sum Condition](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/)

### Difficulty

**${\bf{\color\{green}{Medium}}}$**

### Related Topic

`Sorting` `Two Pointers` `Binary Search` `Sliding Window`

### Code
```cpp

class Solution {
const int mod = 1e9 + 7; // the answer must be modulo 1e9 + 7
public:
    int numSubseq(vector<int>& nums, int target) {

      long long ans = 0; // the answer
      sort(nums.begin(), nums.end()); // sort the array to use binary search

      // fast power function
      auto fast_pow = [&](long long base, long long power){
        long long res = 1;
        while (power){
          if (power & 1) res = (res * base) % mod;
          base = (base * base) % mod;
          power >>= 1;
        }
        return res;
      };
 
      
      for (int i = 0; i < int(nums.size()); i++){
        // find the index of the largest element that is less than or equal to target - nums[i] 
        long long j = upper_bound(nums.begin(), nums.end(), target - nums[i]) - nums.begin() - 1;
        // if j >= i then the number of subsequences that satisfy the condition is 2 ^ (j - i) 
        if (j >= i) ans = (ans + fast_pow(2, j - i)) % mod;
      }   
      // return the answer
      return ans;         
    }
};
```

## 7)  [Find the Longest Valid Obstacle Course at Each Position](https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/)

### Difficulty

**${\bf{\color\{green}{Hard}}}$**

### Related Topic

`Array` `Binary Search` `binary Indexed Tree` 

### Code
```cpp
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector < int > ans; // answer
        // build[i]: the minimum value of the last element of a subsequence of length i
        vector < int > build(int(obstacles.size()) + 1, 1e9);
        for (auto & i: obstacles){
            // find the index of the smallest element that is greater than or equal to i
            auto it = upper_bound(build.begin(), build.end(), i) - build.begin();
            build[it] = i; // update the value of build[it]
            ans.push_back(it + 1); // update the answer
        }
        return ans; // return the answer
    }
};
```

<hr><br>

## 8)  [Matrix Diagonal Sum](https://leetcode.com/problems/matrix-diagonal-sum/)

### Difficulty

**${\bf{\color\{green}{Easy}}}$**

### Related Topic

`Array` `Matrix`

### Code
```cpp
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
       // the sum of the elements in the main diagonal and the secondary diagonal
       long long sum = 0; 

       // the size of the matrix
       int n = mat[0].size();

       // the sum of the elements in the main diagonal 
       for (int i = 0; i < n; i++) sum += mat[i][i];

        // the sum of the elements in the secondary diagonal       
       for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++)
            if ((i + j) == n - 1 && i != j)
               sum += mat[i][j];

        // return the sum
        return sum;        
    }
};
```

<hr><br>

## 9)  [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)

### Difficulty

**${\bf{\color\{green}{Medium}}}$**


### Related Topic

`Array` `Matrix` `Simulation`

### Code
```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector < int > ans; // to store the answer
        int n = matrix.size(), m = matrix[0].size();

        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        
        // build the answer
        while(top <= bottom && left <= right){
            // go right 
            for(int i = left; i <= right; i++) ans.push_back(matrix[top][i]);

            // we have already visited the top row
            top++; 

            // go down            
            for(int i = top; i <= bottom; i++) ans.push_back(matrix[i][right]);
            
            // we have already visited the right column
            right--;

            // go left
            if(top <= bottom){
                for(int i = right; i >= left; i--) ans.push_back(matrix[bottom][i]);
                // we have already visited the bottom row
                bottom--;
            }

            // go up
            if(left <= right){
                for(int i = bottom; i >= top; i--) ans.push_back(matrix[i][left]);
                // we have already visited the left column
                left++;
            }
        }
        // return the answer
        return ans;
    }
};
```

<hr><br>

## 10)  [Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/)

### Difficulty

**${\bf{\color\{green}{Medium}}}$**

### Related Topic

`Array` `Matrix` `Simulation`

### Code
```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

    int val = 1;
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    vector < vector < int > > matrix(n, vector < int > (n));    
    
    // build the answer
    while(top <= bottom && left <= right){
         // go right 
         for(int i = left; i <= right; i++) matrix[top][i] = val++;

          // we have already visited the top row
          top++; 

          // go down            
          for(int i = top; i <= bottom; i++) matrix[i][right] = val++;
          
          // we have already visited the right column
          right--;

          // go left
          if(top <= bottom){
              for(int i = right; i >= left; i--) matrix[bottom][i] = val++;
              // we have already visited the bottom row
              bottom--;
          }

          // go up
          if(left <= right){
              for(int i = bottom; i >= top; i--) matrix[i][left] = val++;
              // we have already visited the left column
              left++;
          }
      }

      return matrix;
    }
};
```

<hr><br>

## 11)  [Uncrossed Lines](https://leetcode.com/problems/uncrossed-lines/)

### Difficulty

**${\bf{\color\{green}{Medium}}}$**

### Related Topic

`Array` `Dynamic Programming`

### Code
```cpp
class Solution {
#define all(s) s.begin(), s.end()
public:
    vector < int > a; // nums1
    int dp[2005][2005]; // dp[i][j]: the answer for the subproblem of nums1[i..n] and nums2[j..m]
    vector < int > Idx[2005]; // Idx[i]: the indices of i in nums2

    int get_max(int i, int j){
      if (i == int(a.size())) return 0; // base case

      // memoization
      int &ret = dp[i][j];
      if (~ret) return ret;
      
      ret = get_max(i + 1, j); // skip nums1[i]
      auto it = upper_bound(all(Idx[a[i]]), j); // find the index of the smallest element that is greater than or equal to j

      // if there is an element in Idx[a[i]] that is greater than or equal to j then we can take nums1[i]
      if (it != Idx[a[i]].end())
        ret = max(ret, 1 + get_max(i + 1, *it));

      // return the answer  
      return ret;
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
      a = nums1; // copy nums1 to a

      // build Idx
      for (int i = 0; i < int(nums2.size()); i++)
        Idx[nums2[i]].push_back(i + 1);

      // initialize dp with -1    
      memset(dp, -1, sizeof(dp));

      // return the answer
      return get_max(0, 0);
    }
};
```


<hr><br>

## 12)  [Solving Questions With Brainpower](https://leetcode.com/problems/solving-questions-with-brainpower/)

### Difficulty

**${\bf{\color\{green}{Medium}}}$**


### Related Topic

`Array` `Dynamic Programming`

### Code
```cpp
class Solution {
public:
    long long dp[int(1e5 + 5)]; // dp array 
    vector < vector < int > > questions; // questions vector 
    long long get_min(int Idx){
      if (Idx >= int(questions.size())) return 0; // base case
      
      // memo
      long long &ret = dp[Idx]; 
      if (~ret) return ret;
  
      // skip this question
      ret = get_min(Idx + 1);

      // take the max between skip and take this question 
      ret = max(ret, get_min(Idx + questions[Idx][1] + 1) + questions[Idx][0]);
      return ret;
    }

    long long mostPoints(vector<vector<int>>& questions) {
      this -> questions = questions;
      memset(dp, -1, sizeof(dp));
      return get_min(0);
    }
};
```

<hr><br>

## 13)  [Count Ways To Build Good Strings](https://leetcode.com/problems/count-ways-to-build-good-strings/description/)

### Difficulty

**${\bf{\color\{green}{Medium}}}$**

### Related Topic

`Dynamic Programming`

### Code
```cpp
class Solution {
public:
    int z, o; // the number of zeros and ones
    long long dp[int(1e5 + 5)]; // dp array
    long long count(long long val){ // count the number of good strings
        // base case
        if (val <= 0) return val == 0; 
       
        // memo
        long long &ret = dp[val]; 
        if (~ret) return ret;
        
        // count the number of good strings 
        return ret = (count(val - o) + count(val - z)) % int(1e9 + 7);
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0; // the answer
        o = one, z = zero; // initialize the number of zeros and ones
        memset(dp, -1, sizeof(dp)); // initialize dp with -1

        // count the number of good strings in the range [low, high]
        for (int i = low; i <= high; i++)
            ans = (ans + int(1e9 + 7) + count(i)) % int(1e9 + 7); 

        // return the answer        
        return ans;
    }
};
```

<hr><br>


## 14)  [Maximize Score After N Operations](https://leetcode.com/problems/maximize-score-after-n-operations/)

### Difficulty

**${\bf{\color\{green}{Hard}}}$**

### Related Topic

`Dynamic Programming` `Bitmask`

### Code
```cpp
class Solution {
// some definitions    
#define ll long long  
#define sz(nums) int(nums.size())
#define mod 1000000007
public:
  ll full = 0; // full mask (make all bits 1)
  ll dp[1 << 16][16]; // dp array
  vector < int > nums; // nums vector

  // get bit at position pos from mask
  bool getbit(ll mask, int pos){
    return (mask >> pos) & 1;
  }

  // get the maximum score
  ll get_max(ll mask, int Idx){
    // base case (all bits are 1)
    if (mask == full) return 0; 

    // memoization
    ll &ret = dp[mask][Idx];
    if (~ret) return ret;
    
    ret = 0;

    // try all pairs of numbers 
    for (int bit = 0; bit < sz(nums); bit++){
      // if the bit is already taken then skip it
      if (getbit(mask, bit)) continue; 
      for (int bit2 = bit + 1; bit2 < sz(nums); bit2++){
        // if the bit is already taken then skip it
        if (getbit(mask, bit2)) continue;
        // take the max between skip and take this pair of numbers
        ret = max(ret, get_max(mask | (1LL << bit) | (1LL << bit2), Idx + 1) + (Idx + 1) * __gcd(nums[bit], nums[bit2]));
        ret %= mod; // modulo
      }
    }
    // return the answer
    return ret %= mod;
  }


  int maxScore(vector<int>& nums) {
    full = (1LL << sz(nums)) - 1; // full mask
    this -> nums = nums; // copy nums to this -> nums
    memset(dp, -1, sizeof(dp)); // initialize dp with -1
    return get_max(0, 0); // return the answer
  }

};
```

<hr><br>



