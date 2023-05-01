class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
       long long ans = 0, cnt = 0;
       nums.push_back(1); // add 1 to the end of the array to count the last subarray
       for (auto & i: nums){
           cnt += (i == 0); // count the number of zeros
           // if i is not zero, add the number of subarrays that can be formed with the zeros
           // and reset the counter to zero
           if (i != 0) ans += cnt * (cnt + 1) / 2, cnt = 0;
       }
       return ans;
    }
};