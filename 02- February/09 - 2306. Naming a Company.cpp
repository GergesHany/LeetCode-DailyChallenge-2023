class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int ans = 0; 
        vector < unordered_set < string > > words(26); // 26 letters in the alphabet 
        for (auto & i: ideas) 
           words[i[0] - 'a'].insert(i.substr(1)); // insert the word without the first letter
        
        // for each pair of words, we count the number of distinct letters in the two words 
        for (int i = 0; i < 25; i++){
            // for each word, we count the number of distinct letters in the word
            for (int j = i + 1; j < 26; j++){
                // we count the number of distinct letters in the two words
                unordered_set < string > st; // set of distinct letters in the two words
                st.insert(words[i].begin(), words[i].end()); // insert the letters of the first word
                st.insert(words[j].begin(), words[j].end());  // insert the letters of the second word
                // we count the number of distinct letters in the two words 
                ans += (int(words[j].size()) - int(st.size())) * (int(words[i].size()) - int(st.size()));
            }
        }
        return 1LL * ans * 2; // we multiply by 2 because we counted each pair twice
    }
};
