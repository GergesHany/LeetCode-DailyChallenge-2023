class Solution {
#define sz(s) int(s.size()) 
#define ll long long
#define all(s) s.begin(), s.end()
public:
  ll dp[1005][1005]; // dp[Idx][prve] = max score if we take the idx and the previous idx is prve
  vector < pair < ll, ll > > build; // build[i] = {age, score}
  // we will sort the build vector by age and then we will try to take the idx and the previous idx
  ll get_max(int Idx, ll prve){
    if(Idx == sz(build) - 1) return 0; // if we reach the end of the vector
    // if we take the idx and the previous idx is prve
    ll &ret = dp[Idx][prve]; 
    if(~ret) return ret;
    ret = 0; // if we don't take the idx
    // if the age of the idx is greater than the age of the previous idx then we can take the idx
    if(build[Idx].second >= build[prve].second) 
      ret = max(ret, build[Idx].second + get_max(Idx + 1, Idx)); // take the idx
    ret = max(ret, get_max(Idx + 1, prve)); // don't take the idx
    return ret; // return the maximum
  }

  int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    ll n = sz(scores);
    build = vector < pair < ll, ll > > (n); // build[i] = {age, score}
    for(int i = 0; i < n; i++) build[i] = {ages[i], scores[i]}; 
    sort(all(build)); // sort the build vector by age 
    build.push_back({-10, -10}); // add a dummy element to the end of the vector
    memset(dp, -1, sizeof dp); // initialize the dp array with -1
    return get_max(0, n); // return the maximum score
  }
};