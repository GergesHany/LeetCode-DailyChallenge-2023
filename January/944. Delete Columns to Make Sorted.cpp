#define sz(s) int(s.size())  
#define all(vec) vec.begin(), vec.end()
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt = 0;
        for(int i = 0; i < sz(strs[0]); i++){ // loop on the columns
          string s;
          for(int j = 0; j < sz(strs); j++) 
            s += strs[j][i]; // get the column
          if(!is_sorted(all(s))) cnt++; // check if the column is sorted
        }
        return cnt;
    }
};