class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        if(numRows == 1) return s; // if numRows == 1, return s directly
        int n = s.size(); // get the size of s
        int cycle = 2 * numRows - 2; // get the cycle of the zigzag pattern
        for(int i = 0; i < numRows; i++){ // loop over the rows
            for(int j = 0; j + i < n; j += cycle){ // loop over the columns
                ans += s[j + i]; // add the character in the current row
                // add the character in the middle of two adjacent rows if it exists 
                if(i != 0 && i != numRows - 1 && j + cycle - i < n){ 
                    ans += s[j + cycle - i];
                }
            }
        }
        return ans; // return the answer
    }
};