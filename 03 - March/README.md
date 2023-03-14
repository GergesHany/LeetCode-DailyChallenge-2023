## LeetCode Daily Challenge Problems for March

## Problems:

1. **[Sort an Array](#1--Sort-an-Array)**
1. **[String Compression](#2--String-Compression)**
1. **[Find the Index of the First Occurrence in a String](#3--Find-the-Index-of-the-First-Occurrence-in-a-String)**
1. **[Count Subarrays With Fixed Bounds](#4--count-subarrays-with-fixed-bounds)**
1. **[Jump Game IV](#5--jump-game-iv)**
1. **[Kth Missing Positive Number](#06--kth-missing-positive-number)**
1. **[Minimum Time to Complete Trips](#07--minimum-time-to-complete-trips)**
1. **[Koko Eating Bananas](#08--koko-eating-bananas)**
1. **[Linked List Cycle II](#09--linked-list-cycle-ii)**
1. **[Linked List Random Node](#10--linked-list-random-node)**
1. **[Convert Sorted List to Binary Search Tree](#11--convert-sorted-list-to-binary-search-tree)**
1. **[Merge k Sorted Lists](#12--Merge-k-Sorted-Lists)**
1. **[Symmetric Tree](#13--Symmetric-Tree)**
1. **[ Sum Root to Leaf Numbers](#13--Sum-Root-to-Leaf-Numbers)**



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
       int Idx =  haystack.find(needle);
       return Idx;
    }
};
```

<hr>

<br><br>

## 4)  [Count Subarrays With Fixed Bounds](https://leetcode.com/problems/count-subarrays-with-fixed-bounds/)

### Difficulty

**${\bf{\color\{red}\{Hard}}}$**

### Related Topic

`Array` `Queue` `Sliding Window` `Monotonic Queue`

### Code


```cpp
class Solution {
#define sz(s) int(s.size())    
#define all(s) s.begin(), s.end()    
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
       long long ans = 0; 
       // Idx_min = index of minK, Idx_max = index of maxK, last = index of last element that is not in range [minK, maxK]
       int Idx_min = -1, Idx_max = -1, last = -1;
       for (int i = 0; i < sz(nums); i++){
          // if nums[i] is in range [minK, maxK] then we can add all subarrays that start from last element that is not in range [minK, maxK] to nums[i]

          if (nums[i] == minK) Idx_min = i; // update Idx_min
          if (nums[i] == maxK) Idx_max = i; // update Idx_max
          // if nums[i] is not in range [minK, maxK] then we can't add any subarray that start from last element that is in range [minK, maxK] to nums[i]
          if (nums[i] > maxK || nums[i] < minK) last = i, Idx_min = Idx_max = -1;
          // if Idx_min and Idx_max are not -1 then we can add all subarrays that start from last element that is not in range [minK, maxK] to nums[i] 
          if (~Idx_min && ~Idx_max) ans += min(Idx_min, Idx_max) - last;
       }
       return ans; // return answer
    }
};
```
<hr>

<br><br>

## 5)  [Jump Game IV](https://leetcode.com/problems/jump-game-iv/)

### Difficulty

**${\bf{\color\{red}\{Hard}}}$**

### Related Topic

`Array` `Hash Table` `Breadth-First Search`

### Code


```cpp
class Solution {
#define ll long long  
#define INF 1e18   
#define all(s) s.begin(), s.end()
#define sz(s) int(s.size())
public:
    int minJumps(vector<int>& arr) {
        int n = sz(arr);
        if(n == 1) return 0;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) mp[arr[i]].push_back(i);
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int u = q.front();
                q.pop();
                if(u == n - 1) return ans;
                if(u - 1 >= 0 && !vis[u - 1]){
                    q.push(u - 1);
                    vis[u - 1] = 1;
                }
                if(u + 1 < n && !vis[u + 1]){
                    q.push(u + 1);
                    vis[u + 1] = 1;
                }
                for(auto v : mp[arr[u]]){
                    if(!vis[v]){
                        q.push(v);
                        vis[v] = 1;
                    }
                }
                mp[arr[u]].clear();
            }
            ans++;
        }
        return ans;
    }
};
```

<hr>
<br><br>

## 06)  [Kth Missing Positive Number](https://leetcode.com/problems/kth-missing-positive-number/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`Array` `Binary Search`

### Code


```cpp
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans = 0; // the answer
        // set to store the elements of the array 
        set < int > st(arr.begin(), arr.end());
        // loop over the numbers from 1 to 2005 to find the kth missing number
        for (int i = 1; i <= 2005; i++){
          // if the number is not in the set then decrease k by 1
            if (st.find(i) == st.end()){
                k--;
                // if k is 0 then the answer is i and break the loop
                if (k == 0){
                    ans = i;
                    break;
                }
            }
        }
        return ans; // return the answer
    }
};
```
    

<hr>
<br><br>

## 07)  [Minimum Time to Complete Trips](https://leetcode.com/problems/minimum-time-to-complete-trips/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Array` `Binary Search`

### Code


```cpp
class Solution {
#define ll long long
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll l = 0, r = 1, ans = time[0]; 
        // function to check if the mid is good or not  
        auto is_good = [&](ll mid) -> bool {
          ll sum = 0;
          for (auto & i: time) sum += mid / i;
          return sum >= totalTrips; 
        };

       // find the first good number and then do binary search 
       while(!is_good(r)) r *= 2;

        // binary search 
        while(l <= r){
            ll mid = l + (r - l) / 2;
            // if the mid is good then store it and try to find a smaller one
            if (is_good(mid)) ans = mid, r = mid - 1;
            // else try to find a bigger one
            else l = mid + 1;
        }
        return ans; // return the answer
    }      
};
```
    
<hr>
<br><br>

## 08)  [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Array` `Binary Search`

### Code


```cpp
class Solution {
#define ceill(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1;
        auto is_good = [&](int mid) -> bool {
           long long sum = 0;
           for (auto & i: piles)
             sum += ceill(i, mid);
           return sum <= h;     
        };
        
        int ans = 0;
        while(!is_good(r)) r *= 2;
        while(l <= r){
            long long mid = l + (r - l) / 2;
            if (is_good(mid)) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        return ans;
    }
};
```
    
<hr>
<br><br>

## 09)  [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Hash Table` `Linked List` `Two Pointers`

### Code


```cpp
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head; // slow pointer
        ListNode *fast = head; // fast pointer
        // if there is a cycle, the fast and slow pointers will meet at some point 
        while(fast && fast -> next){
            // move slow pointer one step and fast pointer two steps
            slow = slow -> next;
            fast = fast -> next -> next;
            // if the fast and slow pointers meet, there is a cycle
            if(slow == fast){
                // move slow pointer to the head
                ListNode *temp = head;
                // move both pointers one step at a time until they meet at the start of the cycle 
                while(temp != slow){
                  // move both pointers one step at a time
                    temp = temp -> next;
                    slow = slow -> next;
                }
                return temp; // return the start of the cycle
            }
        }
        return NULL; // there is no cycle
    }
};
```

<hr>
<br><br>

## 10)  [Linked List Random Node](https://leetcode.com/problems/linked-list-random-node/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Linked List` `Math` `Reservoir Sampling` `Randomized`

### Code


```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution{
    int n;
    vector < int > build;

public:
    Solution(ListNode *head){
        ListNode *ptr = head;
        while (ptr){
            build.push_back(ptr->val);
            ptr = ptr->next;
        }
        n = v.size();
    }

    int getRandom(){
        return v[rand() % n];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
```

<hr>
<br><br>

## 11)  [Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Linked List` `Divide and Conquer` `Tree` `Binary Search Tree` `Binary Tree`

### Code


```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* solve(ListNode* head, ListNode* tail){
        if(head == tail) return nullptr; // base case
        // find the middle element of the list and make it the root of the tree 
        ListNode* slow = head, *fast = head;
        // slow will be the middle element of the list 
        while(fast != tail && fast->next != tail){
            slow = slow->next; // move slow by one step
            fast = fast->next->next; // move fast by two steps
        }
        // slow is the middle element of the list 
        TreeNode* root = new TreeNode(slow->val); // make it the root of the tree
        // recursively build the left and right subtrees of the root
        root->left = solve(head, slow);
        root->right = solve(slow->next, tail);
        return root; // return the root of the tree
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return solve(head, nullptr); // call the recursive function
    }
};
```


## 12)  [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)

### Difficulty

**${\bf{\color\{red}\{Hard}}}$**

### Related Topic

`Linked List` `Divide and Conquer` `Heap(priority queue)` `Merge sort`

### Code


```cpp
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector < int > ans;
        for(int i = 0; i < lists.size(); i++){
            ListNode* head = lists[i];
            while(head != nullptr){
                ans.push_back(head->val);
                head = head->next;
            }
        }
        
        sort(ans.begin(), ans.end(), greater<int>());
        ListNode *answer = NULL;
        for (int x: ans){
            ListNode* temp = new ListNode;
            temp -> val = x;
            temp -> next = answer;
            answer = temp;
        }
        return answer;
    }
};
```


## 13)  [Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)

### Difficulty

**${\bf{\color\{orange}\{Madium}}}$**

### Related Topic

`Tree` `Depth-First-search` `Breadth-First-search` `Bainry Tree`

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
    // function to reverse right subtree
    void reverse(TreeNode* root){
        if (!root) return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        reverse(root->left);
        reverse(root->right);
    }

    // function to check if two trees are same
    bool is_same(TreeNode* root1, TreeNode* root2){
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        if (root1->val != root2->val) return false;
        return is_same(root1->left, root2->left) && is_same(root1->right, root2->right);
    }
   
    bool isSymmetric(TreeNode* root) {
        if (!root) return false; // if root is null
        // if root is not null
        // reverse right subtree
        // check if left subtree and reversed right subtree are same
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        reverse(right);
        return is_same(left, right);
    }
};
```

## 14)  [Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers/description/)

### Difficulty

**${\bf{\color\{orange}\{Madium}}}$**

### Related Topic

`Tree` `Depth-First-search` `Bainry Tree`

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
    
   long long ans = 0;
   void get_ans(TreeNode* root, long long build){
     if (!root) return;
      build = build * 10 + root->val;
      if (!root->left && !root->right) ans += build;
      get_ans(root->left, build);
      get_ans(root->right, build);
   } 

    int sumNumbers(TreeNode* root) {
      get_ans(root, 0);
      return ans;  
    }
};
```










