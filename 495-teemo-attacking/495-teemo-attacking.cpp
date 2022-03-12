class Solution {
public:
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int ans = duration, end = timeSeries[0] + duration - 1;
    for(int i=1;i<timeSeries.size();i++)
    {
      ans += duration;
      int overLappingDuration = timeSeries[i] - end - 1;
      if(overLappingDuration<0)
        ans += overLappingDuration;
      end = timeSeries[i] + duration - 1;
    }
    return ans;
  }
};