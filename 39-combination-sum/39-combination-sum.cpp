class Solution {
public:
  void createCombinationSum(vector<int>& candidates, int target, int currentIndex, int currentSum, vector<int> &currentCombination, vector<vector<int>> &res)
  {
    if(currentSum == target)
    {
      res.push_back(currentCombination);
      return;
    }
    if(currentSum > target)
      return;
    for(int i = currentIndex;i<candidates.size();i++)
    {
      currentCombination.push_back(candidates[i]);
      createCombinationSum(candidates, target, i, currentSum + candidates[i], currentCombination, res);
      currentCombination.pop_back();
    }
  }
  
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int>currentCombination(0);
    createCombinationSum(candidates, target, 0, 0, currentCombination, res);
    return res;
  }
};