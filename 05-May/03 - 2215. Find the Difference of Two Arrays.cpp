class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // map to count the frequency of each element
        map < int, int > a, b; 

        // count the frequency of each element in nums1 and nums2
        for (auto & i: nums1) a[i]++;
        for (auto & i: nums2) b[i]++;
        
        vector < int > A, B; // A: elements in nums1 but not in nums2, B: elements in nums2 but not in nums1
        // find the elements in nums1 but not in nums2
        for (auto & i: nums1) if (!b[i]) B.push_back(i), b[i] = 1;
        // find the elements in nums2 but not in nums1
        for (auto & i: nums2) if (!a[i]) A.push_back(i), a[i] = 1;
        // the answer is the union of A and B
        vector < vector < int > > ans = {B, A};
        // return the answer
        return ans; 
    }
};