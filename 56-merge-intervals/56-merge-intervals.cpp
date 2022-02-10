class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      int n = intervals.size();
      sort(intervals.begin(), intervals.end());
      // sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int>  &b) -> bool{return a[0] <= b[0];});
      vector<vector<int>> ans;
      vector<int>cur{intervals[0][0], intervals[0][1]};
      for(int i=1;i<n;i++)
      {
        if(intervals[i][0] <= cur[1])
        {
          //overlap
          cur[1] = max(cur[1], intervals[i][1]);
        }
        else
        {
          ans.push_back(cur);
          cur[0] = intervals[i][0];
          cur[1] = intervals[i][1]; 
        }
      }
      ans.push_back(cur);
      return ans;
    }
};