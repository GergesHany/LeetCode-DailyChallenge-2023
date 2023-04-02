class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      vector < int > ans;
      int n = s.size(), m = p.size();
      if (n < m) return ans; // if the size of the string is less than the size of the pattern
      vector < int > cnt(26); // count the frequency of each character in the pattern
      for (char c : p) cnt[c - 'a']++; // count the frequency of each character in the pattern
      for (int i = 0; i < m; i++) cnt[s[i] - 'a']--; // count the frequency of each character in the string
      bool ok = true; // check if the frequency of each character in the string is equal to the frequency of each character in the pattern
      for (int i = 0; i < 26; i++) if (cnt[i]) ok = false; // check if the frequency of each character in the string is equal to the frequency of each character in the pattern
      if (ok) ans.push_back(0); // if the frequency of each character in the string is equal to the frequency of each character in the pattern
      for (int i = m; i < n; i++) { // slide the window over the string
        cnt[s[i] - 'a']--; // minus the frequency of the last character in the string
        cnt[s[i - m] - 'a']++; // count the frequency of each character in the string
        ok = true; // check if the frequency of each character in the string is equal to the frequency of each character in the pattern
        for (int i = 0; i < 26; i++) if (cnt[i]) ok = false; // check if the frequency of each character in the string is equal to the frequency of each character in the pattern
        if (ok) ans.push_back(i - m + 1); // if the frequency of each character in the string is equal to the frequency of each character in the pattern
      }
      return ans; // return the answer
    }
};
