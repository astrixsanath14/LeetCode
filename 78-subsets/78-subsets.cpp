class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      int n = nums.size(), count=1;
      vector<vector<int>> ans(1);
      for(int num:nums)
      {
        vector<vector<int>> curNumCombo = ans;
        for(vector<int> curAns : ans)
        {
          vector<int> temp = curAns;
          temp.push_back(num);
          curNumCombo.push_back(temp);
        }
        ans = curNumCombo;
      }
      return ans;
    }
};