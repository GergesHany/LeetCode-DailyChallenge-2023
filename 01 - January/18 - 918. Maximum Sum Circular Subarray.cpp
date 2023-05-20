class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // Kadane's Algorithm
        int totalSum = 0, maxSum = INT_MIN, curMax = 0, minSum = INT_MAX, curMin = 0;
        for (int x : nums) {
            curMax = max(x, curMax + x);  // max sum of the subarray
            maxSum = max(maxSum, curMax); // update the max sum of the subarray
            curMin = min(x, curMin + x);  // min sum of the subarray
            minSum = min(minSum, curMin); // update the min sum of the subarray
            totalSum += x; // sum of the array
        }
        // if the max sum of the subarray is greater than 0 then we can subtract the min sum of the subarray from the total sum of the array to get a max circular subarray
        // else we can't subtract the min sum of the subarray from the total sum of the array
        return maxSum > 0 ? max(maxSum, totalSum - minSum) : maxSum;
    }
};