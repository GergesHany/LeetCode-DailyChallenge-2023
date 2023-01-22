class Solution {
#define sz(s) int(s.size())
public: 
   // fucntion to check if all the strings in the vector are plandromes or not
   bool is_valid(vector < string > build){
       auto is_plandrome = [](string s){
           for (int i = 0; i < sz(s) / 2; i++)
              if (s[i] != s[sz(s) - i - 1])  return false;
            return true;     
        };    

       for (auto & i: build) 
         if (!is_plandrome(i)) return false;
        return true;
    }

    // vector to store the answer
    vector < vector < string > > ans;
    
    // backtraking function
    void backtraking(string s, int Idx){
        if (Idx == sz(s)){ // base case
          vector < string > build; // vector to store the current build
          // slpit the string into substrings
          for (int i = 0; i < sz(s); i++){
              string tmp;
              while (i < sz(s) && s[i] != ' ') 
               tmp += s[i++];
              build.push_back(tmp);
          }
          // check if the current build is valid or not
          if (is_valid(build))   
            ans.push_back(build);
          return;  
        }   
        // if the current character is space or the last character in the string 
        // then we don't need to cut the string
        if (s[Idx] == ' ' || (Idx == sz(s) - 1)) 
           backtraking(s, Idx + 1); // call the function with the next index
        else{
          // cut the string at the current index
          backtraking(s, Idx + 1);
          // insert space at the current index to cut the string
          s.insert(Idx + 1, " ");
          // call the function with the next of the next index 
          // because we inserted space at the current index
          backtraking(s, Idx + 2);  
          s = s.substr(0, Idx + 1) + s.substr(Idx + 2); // remove the space
        }
    }
    
    vector<vector<string>> partition(string s) {
        backtraking(s,  0); // call the backtraking function
        return ans; // return the answer
    }
};