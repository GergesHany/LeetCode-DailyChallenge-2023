class Solution {
public:
    int compress(vector<char>& chars) {
        string temp; // temp string to store the compressed string
        for (auto & i: chars) temp += i; // convert vector to string 
        int ans = 0, cnt = 1, n = temp.size();
        // loop over the string and compress it
        for (int i = 0; i < n; i++){
          int Idx = i + 1;  // index to loop over the string
          char c = temp[i]; // current character
          // loop over the string to count the number of the current character
          while (Idx < n && temp[Idx] == c) Idx++, cnt++;
          // add the current character to the compressed string
          while(cnt > 0){
            chars[ans++] = c; // add the current character
            // add the number of the current character if it's more than 1
            if (cnt > 1){
              // convert the number to string
              string s = to_string(cnt);
              // add the number to the compressed string
              for (auto & i: s) chars[ans++] = i;
            }
            // break the loop
            break;
          }
          // update the index and the number of the current character
          i = Idx - 1, cnt = 1;
        }
        // return the size of the compressed string
        return ans;
    }
};
