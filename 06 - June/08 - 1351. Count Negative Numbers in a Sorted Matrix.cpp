class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0; // count of negative numbers
        for (auto & i: grid) 
        // for each row, count the number of negative numbers in it and add to ans 
          ans += count_if(i.begin(), i.end(), [](int x){ return x < 0; });
        // return the answer  
        return ans;
    }
};