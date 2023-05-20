class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int cumSum = 0; // sum of the subarray
        int n = nums.size(); 
        vector < int > mod(k, 0); // build the mod of the sum of the subarray

        for (int i = 0; i < n; i++) {
            cumSum += nums[i]; // sum of the subarray
            mod[((cumSum % k) + k) % k]++; // mod of the sum of the subarray 
        }

        int ans = 0; 
        for (int i = 0; i < k; i++)
        // if the mod of the sum of the subarray is greater than 1
        // then we can subtract the two subarrays to get a subarray with sum = 0
            if (mod[i] > 1) 
                ans += (mod[i] * (mod[i] - 1)) / 2;


        return ans + mod[0]; // add the subarrays with sum = 0
    }
};