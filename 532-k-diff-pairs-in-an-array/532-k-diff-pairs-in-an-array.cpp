class Solution {
public:
  int findPairs(vector<int>& nums, int k) {
      unordered_multiset<int> ums(nums.begin(), nums.end());
      unordered_set<int> us(nums.begin(), nums.end());
      int ret = 0;
      for (int i : us) if (ums.count(i + k) > !k) 
        ++ret;
      return ret;
  }
};