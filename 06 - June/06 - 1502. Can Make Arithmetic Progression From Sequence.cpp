class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        // sort the array
        sort(arr.begin(), arr.end()); 
        
        // check if the difference between first two elements is same as the difference between the next two elements
        for (int i = 1; i < int(arr.size()); i++)
           // if the difference is not same, return false
            if ((arr[i] - arr[i - 1]) != (arr[1] - arr[0]))
               return false;
        // if the difference is same, return true
        return true;
    }
};