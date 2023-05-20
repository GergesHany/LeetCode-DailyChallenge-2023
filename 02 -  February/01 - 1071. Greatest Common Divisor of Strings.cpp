class Solution {
#define sz(s) int(s.size())
public:
    // check if s is valid string to be repeated to get t
    bool is_valid(string s, string t){
       string temp = s;
        while(sz(temp) < sz(t)) // repeat s until it's length is greater than t
            temp += s; // repeat s 
        return temp == t; // check if temp is equal to t
    }
    string gcdOfStrings(string str1, string str2) {
      string ans = ""; 
        for (int i = 0; i < sz(str1); i++) {
            string temp = str1.substr(0, i + 1); // get the prefix of str1
            if (is_valid(temp, str1) && is_valid(temp, str2)){ // check if temp is valid string to be repeated to get str1 and str2
                if (sz(temp) >= sz(ans)) // get the longest valid string
                    ans = temp; // update the answer
            }
        }
        return ans; // return the answer
    }
};