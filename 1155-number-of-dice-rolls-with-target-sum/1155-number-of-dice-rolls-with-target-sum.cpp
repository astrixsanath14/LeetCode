#define MOD (int)(1e9+7)
class Solution {
public:
  int dp[31][1001];
  int numRollsToTarget(int n, int k, int target, int sum) {
    if(n==0)
      return sum==target;
    if(sum>=target)
      return 0;
    if(dp[n][sum]!=-1)
      return dp[n][sum];
    int ways=0;
    for(int i=1; i<=k; i++)
      ways = (ways%MOD + numRollsToTarget(n-1,k,target,sum+i)%MOD)%MOD;
    return dp[n][sum] = ways;
  }
  
  int numRollsToTarget(int n, int k, int target) {
    for(int i=0;i<=n;i++)
      for(int j=0;j<=target;j++)
        dp[i][j]=-1;
    return numRollsToTarget(n,k,target,0);
  }
};