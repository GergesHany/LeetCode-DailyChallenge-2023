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