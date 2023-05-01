## LeetCode Daily Challenge Problems for May

## Problems:

1. **[Average Salary Excluding the Minimum and Maximum Salary](#1--Average-Salary-Excluding-the-Minimum-and-Maximum-Salary)**



## 1. [Average Salary Excluding the Minimum and Maximum Salary](https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/)

<hr>

<br><br>

## 1)  [Sort an Array](https://leetcode.com/problems/sort-an-array/description/)

### Difficulty

**${\bf{\color\{green}{Easy}}}$**

### Related Topic

`String` `Math`

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