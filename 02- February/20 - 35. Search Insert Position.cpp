class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      // initalize the index with the size of the vector because if the target is greater than all the elements in the vector then the index will be the size of the vector
        int Idx = int(nums.size()); 
        int l = 0, r =  int(nums.size()) - 1; // l = left, r = right
        // binary search
        while(l <= r){
            long long mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) r = mid - 1;
            else l = mid + 1, Idx = mid + 1;
        }  
        if (nums[0] > target) Idx = 0; // if the target is less than the first element in the vector then the index will be 0
        return Idx; // return the index
    }
};