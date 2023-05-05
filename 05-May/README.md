## LeetCode Daily Challenge Problems for May

## Problems:

1. **[Average Salary Excluding the Minimum and Maximum Salary](#1--Average-Salary-Excluding-the-Minimum-and-Maximum-Salary)**
1. **[Sign of the Product of an Array](#2--Sign-of-the-Product-of-an-Array)**
1. **[Find the Difference of Two Arrays](#3--Find-the-Difference-of-Two-Arrays)**
1. **[Dota2 Senate](#4--Dota2-Senate)**
1. **[Maximum Number of Vowels in a Substring of Given Length](#5--Maximum-Number-of-Vowels-in-a-Substring-of-Given-Length)**


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