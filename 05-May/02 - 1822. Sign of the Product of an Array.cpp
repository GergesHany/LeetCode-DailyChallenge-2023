class Solution {
public:
    int arraySign(vector<int>& nums) {
       int neg = 0; // count the number of negative numbers
       for (auto & i: nums){
           // if there is a zero, return 0 immediately 
           // because the product will be zero 
           if (!i) return 0; 
           // count the number of negative numbers
           neg += (i < 0);
       }  
       // if the number of negative numbers is odd, 
       // the product will be negative 
       // otherwise, the product will be positive
       return (neg & 1 ? -1 : 1);
    }
};