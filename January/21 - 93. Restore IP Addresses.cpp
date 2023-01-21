
class Solution {
#define sz(s) int(s.size())
#define all(s) s.begin(), s.end()
public:
    // function to check if the string is valid or not
    bool is_valid(string s){
      // if the point is not 3 and the first character is equal to . is not valid
      if (count(all(s), '.') != 3 || s[0] == '.') return false;
      s = "." + s;
      for (int i = 0; i < sz(s); i++){
         if (s[i] == '.'){ // if the character is equal to . check the string after it
           string temp; // temp string to check the string after the point
           for (int j = i + 1; j < sz(s) && s[j] != '.'; j++)
              temp += s[j]; // add the string to the temp string
           // if the size of the temp string is greater than 3 or equal to 0 is not valid   
           if (sz(temp) > 3 || sz(temp) == 0) return false;
           if (sz(temp) > 1 && temp[0] == '0' || stoi(temp) > 255) return false;
         }
      } 
      return true;
    }

    vector < string > build;
    void Backtracking(int Idx, string s){
        if (Idx == sz(s)) {
          // if the string is valid push it to the vector
           if (is_valid(s)) build.push_back(s);
           return;
        }
        // if the string is equal to . call the function again to check the next character 
        if (s[Idx] == '.') Backtracking(Idx + 1, s);
        else{
          // if the string is not equal to . add the point and call the function again to check the next character
           Backtracking(Idx + 1, s);
           s.insert(Idx, ".");
           Backtracking(Idx + 2, s);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        Backtracking(0, s); // call the function to check the string
        return build; // return the answer
    }
};