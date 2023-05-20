class Solution {
#define all(vec)  vec.begin(),  vec.end()  
public:
    set < vector < int > > ans; // to avoid duplicates
    void Get_all(vector < int >& vec, int Idx, vector < int > build){
       if (Idx == vec.size()){ // base case
          if (is_sorted(all(build)) && build.size() > 1)  // check if it's sorted and not empty
            ans.insert(build); // insert it in the set
          return;
       }
       // recursive case
       Get_all(vec, Idx + 1, build); // don't take the current element
       build.push_back(vec[Idx]); // take the current element
       Get_all(vec, Idx + 1, build); // take the current element
       build.pop_back(); // backtracking
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        Get_all(nums, 0, {}); // call the function
        vector < vector < int > > res(all(ans)); // convert the set to vector of vectors
        return res;
    }
};