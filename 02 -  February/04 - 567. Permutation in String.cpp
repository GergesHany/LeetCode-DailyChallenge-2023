class Solution {
#define sz(s) int(s.size())
#define all(s) s.begin(), s.end()
public:
    bool checkInclusion(string s1, string s2) {
        int n = sz(s1), m = sz(s2); 
        if (n > m) return false; // s1 is bigger than s2 so it can't be a permutation of s2
        vector < int > cnt1(26), cnt2(26); // count of each character in s1 and s2
        for (int i = 0; i < n; i++) {
            cnt1[s1[i] - 'a']++; // count of each character in s1
            cnt2[s2[i] - 'a']++; // count of each character in s2
        }
        // sliding window technique to check if s1 is a permutation of s2
        for (int i = n; i < m; i++) {
            if (cnt1 == cnt2) return true; // if the count of each character in s1 and s2 is the same then s1 is a permutation of s2
            cnt2[s2[i] - 'a']++; // add the new character to the count of s2
            cnt2[s2[i - n] - 'a']--; // remove the first character from the count of s2
        }
        return cnt1 == cnt2;  // check if the last window is a permutation of s1       
    }
};
