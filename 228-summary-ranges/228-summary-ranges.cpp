class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
      vector<pair<int,int>> rangesV;
      for(int i=0;i<nums.size();i++)
      {
        if(i==0)
          rangesV.push_back({nums[i],nums[i]});
        else
        {
          if(nums[i] != nums[i-1]+1)
          {
            rangesV.back().second = nums[i-1];
            rangesV.push_back({nums[i],nums[i]});
          }
          else if(i==nums.size()-1)
            rangesV.back().second = nums[i];
        }
      }
      vector<string> ranges;
      for(pair<int,int> range : rangesV)
      {
        string nextRange = to_string(range.first) + (range.second != range.first ? "->" + to_string(range.second) : "");
        ranges.push_back(nextRange);
      }
      return ranges;
    }
};