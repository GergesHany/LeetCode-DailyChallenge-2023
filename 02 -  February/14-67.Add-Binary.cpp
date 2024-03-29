#define sz(s) s.size()
class Solution {
public:
    string add_Binary(string a, string b) {
    string result = ""; // Initialize result
    int s = 0;          // Initialize digit sum
 
    // Traverse both strings starting from last
    // characters
    int i = sz(a) - 1, j = sz(b) - 1;
    while (i >= 0 || j >= 0 || s == 1){
        // Comput sum of last digits and carry
        s += ((i >= 0) ? a[i] - '0': 0);
        s += ((j >= 0) ? b[j] - '0': 0);
 
        // If current digit sum is 1 or 3, add 1 to result
        result = char(s % 2 + '0') + result;
 
        // Compute carry
        s /= 2;
 
        // Move to next digits
        i--; j--;
    }
    return result;
   }

    
    string addBinary(string a, string b) {
        return add_Binary(a, b);
    }
};
