class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int Min = INT_MAX;  // min value in the heap
        priority_queue<int> pq; // max heap 
        for (int num : nums) {
            // make all numbers even 
            if (num & 1)  num *= 2;
            // insert all numbers in the heap
            pq.push(num);
            // update the min value
            Min = min(Min, num);
        }

        int ans = 1e9; // the answer
        while (true) {
            int maxVal = pq.top(); // the max value in the heap
            pq.pop(); // remove it
            ans = min(ans, maxVal - Min); // update the answer
            if (maxVal & 1) break; // if the max value is odd then break
            maxVal = maxVal / 2; // make it even
            Min = min(Min, maxVal); // update the min value
            pq.push(maxVal); // insert it in the heap
        }
        return ans; // return the answer
    }
};