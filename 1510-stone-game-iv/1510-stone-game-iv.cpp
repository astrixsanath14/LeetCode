// According to Zermelo's_theorem, given n stones, either Alice has a must-win strategy, or Bob has one. Therefore, for Alice, the current state is either "must-win" or "must-lose". But how to determine which one it is?

int dp[100001];

int checkIfCanWinWithStones(int n)
{
  if(dp[n]!=-1)
    return dp[n];
  if(n==0)
    return dp[n] = 0;
  for(int i=1;i*i<=n;i++)
  {
    if(checkIfCanWinWithStones(n-i*i) == 0)
      return dp[n] = 1;
  }
  return dp[n] = 0;
}
class Solution {
public:
  bool winnerSquareGame(int n) 
  {
    memset(dp,-1,sizeof dp);
    return checkIfCanWinWithStones(n);
  }
};