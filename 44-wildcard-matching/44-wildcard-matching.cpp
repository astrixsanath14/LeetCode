vector<vector<int>> dp;
class Solution {
public:
  int solve(string &s, int i, string &p, int j)  
  {
    if(i==s.length())
    {
      if(j==p.length())
        return 1;
      if(p[j]!='*')
        return 0;
      // cout<<"s reached "<<i<<" "<<p[j]<<" "<<j<<"\n";
      return solve(s,i,p,j+1);
    }
    else if(j==p.length())
      return 0;
    else if(dp[i][j] == -1)
    {
      if(s[i] == p[j])
        dp[i][j] = solve(s,i+1,p,j+1);
      else if(p[j] == '?')
        dp[i][j] = solve(s,i+1,p,j+1);
      else if(p[j] == '*')
        dp[i][j] = solve(s,i,p,j+1) || solve(s,i+1,p,j);
      else
        dp[i][j]=0;
      // cout<<s[i]<<" "<<i<<" "<<p[j]<<" "<<j<<" "<<dp[i][j];
      // cout<<"\n";
    }
    return dp[i][j];
  }
  
  bool isMatch(string s, string p) 
  {
    dp.resize(s.length(), vector<int>(p.length(),-1));
    // vector<vector<int>> arr(n, vector<int>(m,VAL));
    // matrix.resize(m, std::vector<int>(n, default_value));
    bool ans=solve(s,0,p,0);
    dp.clear();
    return ans;
  }
};
/*
"aa"
"a"
"aa"
"*"
"acdcb"
"a*c?b"
"aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba"
"a*******b"
*/