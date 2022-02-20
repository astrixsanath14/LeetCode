bool compare(const vector<int> &a, const vector<int> &b)
{
  return a[0]<b[0] || (a[0]==b[0] && b[1]<a[1]);
}

class Solution {
public:
  
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), &compare);
    int count = 1, prevStart = intervals[0][0], prevEnd = intervals[0][1];
    // for(auto &t:intervals)
    // {
    //   cout<<t[0]<<" "<<t[1]<<"\n";
    // }
    for(int i=1;i<intervals.size();i++)
    {
      // cout<<prevStart<<" "<<prevEnd<<" "<<intervals[i][0]<<" "<<intervals[i][1]<<"\n";
      if(!(prevStart<=intervals[i][0] && prevEnd>=intervals[i][1]))
      {
        prevStart = intervals[i][0];
        prevEnd = intervals[i][1];
        count++;
      }
    }
    return count;
  }
};