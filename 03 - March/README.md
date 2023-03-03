## LeetCode Daily Challenge Problems for March

## Problems:

1. **[Sort an Array](#1--Sort-an-Array)**
1. **[String Compression](#2--String-Compression)**
1. **[Find the Index of the First Occurrence in a String](#3--Find-the-Index-of-the-First-Occurrence-in-a-String)**



<hr>

<br><br>

## 1)  [Sort an Array](https://leetcode.com/problems/sort-an-array/description/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`String` `Math`

### Code


```cpp
class Solution {
public:
    void merge(vector < int > &vec, int l, int m, int r){
        int n1 = m - l + 1; // size of the left half
        int n2 = r - m; // size of the right half
        vector < int > L(n1), R(n2); // left and right half of the array
        for (int i = 0; i < n1; i++) L[i] = vec[l + i]; // copy the left half
        for (int i = 0; i < n2; i++) R[i] = vec[m + 1 + i]; // copy the right half
        int i = 0, j = 0, k = l; // i for left half, j for right half, k for the original array
        while (i < n1 && j < n2){ // merge the two halves 
            if (L[i] <= R[j]) vec[k++] = L[i++]; // if the left half is smaller than the right half, put the left half in the original array
            else vec[k++] = R[j++]; // else put the right half in the original array
        }
        // if there are any elements left in the left half or the right half, put them in the original array
        while (i < n1) vec[k++] = L[i++]; 
        while (j < n2) vec[k++] = R[j++]; 
    }

    void merge_sort(vector < int > &vec, int l, int r){
        if (l < r){ // base case
            int m = (l + r) / 2; // mid point of the array 
            merge_sort(vec, l, m); // sort the left half
            merge_sort(vec, m + 1, r); // sort the right half
            merge(vec, l, m, r); // merge the two halves
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, int(nums.size()) - 1);
        return nums;
    }
};
```

<hr>

<br><br>


## 2)  [String Compression](https://leetcode.com/problems/string-compression/description/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`String` `Math`

### Code


```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        string temp; // temp string to store the compressed string
        for (auto & i: chars) temp += i; // convert vector to string 
        int ans = 0, cnt = 1, n = temp.size();
        // loop over the string and compress it
        for (int i = 0; i < n; i++){
          int Idx = i + 1;  // index to loop over the string
          char c = temp[i]; // current character
          // loop over the string to count the number of the current character
          while (Idx < n && temp[Idx] == c) Idx++, cnt++;
          // add the current character to the compressed string
          while(cnt > 0){
            chars[ans++] = c; // add the current character
            // add the number of the current character if it's more than 1
            if (cnt > 1){
              // convert the number to string
              string s = to_string(cnt);
              // add the number to the compressed string
              for (auto & i: s) chars[ans++] = i;
            }
            // break the loop
            break;
          }
          // update the index and the number of the current character
          i = Idx - 1, cnt = 1;
        }
        // return the size of the compressed string
        return ans;
    }
};
```

<hr>

<br><br>


## 3)  [Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`String` `Two pointer` `String matching`

### Code


```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
       int Idx = haystack.find(needle); // find the index of the needle in the haystack
       return Idx; // return the index
    }
};
```

<hr>

<br><br>


