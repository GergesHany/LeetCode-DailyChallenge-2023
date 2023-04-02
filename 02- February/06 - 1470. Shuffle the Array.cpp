class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector < int > ans; // vector to store the answer
        for (int i = 0; i < n; i++) 
          ans.push_back(nums[i]), ans.push_back(nums[i + n]); // push the first half of the array then the second half
        return ans; // return the answer   
    }
};
