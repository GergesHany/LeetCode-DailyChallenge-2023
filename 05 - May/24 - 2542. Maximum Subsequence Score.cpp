class Solution {
public:
    long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size(); 
        // vector to store the pairs of score and index
        vector < vector < int > > pairs(n, vector < int > (2));
        
        for (int i = 0; i < n; i++){
            pairs[i][0] = nums2[i]; // score
            pairs[i][1] = nums1[i]; // index
        }
        
        // sort the pairs in descending order of score  
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return b[0] < a[0];
        });

        // max heap to store the index of nums1 
        priority_queue < int, vector < int >, greater < int > > pq;
        
        // total sum of the scores of the elements in nums2   
        long long res = 0, totalSum = 0;

        // iterate over the pairs
        for (const vector < int >& pair : pairs) {
            pq.push(pair[1]); // push the index of the element in nums1
            totalSum += pair[1]; // add the score of the element in nums1
            // if the size of the heap is greater than k, pop the top element and subtract it from the total sum
            if (pq.size() > k) {
                totalSum -= pq.top();
                pq.pop();
            }
            // if the size of the heap is equal to k, update the result by multiplying the total sum with the score of the element in nums2
            if (pq.size() == k) {
                res = max(res, totalSum * pair[0]);
            }
        }
        // return the result
        return res;
    }
};