class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector < int > ans; // the answer vector
        map < int, int > freq; // the frequency map
        for (auto & i:  nums) freq[i]++; // count the frequency of each number

        // sort the numbers based on their frequency
        sort(nums.begin(), nums.end(), [&](int a, int b){
            if (freq[a] == freq[b]) return a < b;
            return freq[a] > freq[b];
        });
       
        // push the first k numbers in the answer vector
        int n = nums.size();
        for (int i = 0; i < n - 1 && k; i++){
            if (nums[i] != nums[i + 1]){
                ans.push_back(nums[i]);
                k--;
            }
        } 
     
        // if k is not zero, push the last number
        if (k) ans.push_back(nums.back());

        // return the answer vector
        return ans;
    }
};