class Solution {
public:
    bool detectCapitalUse(string s) {
        int upper = 0;
        for (auto & i: s) 
          upper += (isupper(i) ? 1 : 0); // count the number of upper case letters
        return (upper == s.size() ) or !upper or (upper == 1 && isupper(s[0]));
    }
};