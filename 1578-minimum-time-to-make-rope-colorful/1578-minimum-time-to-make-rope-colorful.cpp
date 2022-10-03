class Solution {
public:
  int minCost(string colors, vector<int>& neededTime) {
    char color = colors[0];
    int ind = 1;
    int n = colors.length();
    long result = 0;
    while(ind<n)
    {
      if(color == colors[ind])
      {
        int sum = neededTime[ind-1];
        int maxTime = sum;
        while(color == colors[ind] && ind<n)
        {
          sum += neededTime[ind];
          maxTime = max(maxTime, neededTime[ind]);
          ind++;
        }
        result += sum-maxTime;
      }
      if(ind<n)
        color=colors[ind++];
    }
    return result;
  }
};