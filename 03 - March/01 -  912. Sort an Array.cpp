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