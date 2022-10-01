class Solution {
public:
  int dp[101];
  int numDecodings(string s, int i) {
    if(i >= s.length())
    {
      return 1;
    }
    if(dp[i]!=-1)
      return dp[i];
    if(s[i] == '0')
      return dp[i] = 0;
    int ans = numDecodings(s, i+1);
    if((i+1 < s.length()) && ((s[i]=='1') || (s[i]=='2' && s[i+1]<='6')))
      ans += numDecodings(s, i+2);
    // cout<<i<<" ans: "<<ans<<"\n";
    return dp[i] = ans;
  }
  
  int numDecodings(string s) {
    for(int i=0;i<s.length();i++)  
      dp[i] = -1;
    return numDecodings(s,0);
  }
};