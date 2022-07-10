class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    int l=cost.size();
    vector<int> s(l,0);
    s[0] = cost[0];
    s[1] = cost[1];
    for(int i=2;i<l;i++)
    {
      s[i] = cost[i] + min(s[i-1], s[i-2]);
    }
    return min(s[l-1],s[l-2]);
  }
};