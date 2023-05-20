class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0; // 0 ^ x = x and x ^ x = 0
        // so we can xor all the elements and the result will be the single element 
        for (auto x : nums) ans ^= x;  // find the single element
        return ans; // return the single element
    }
};