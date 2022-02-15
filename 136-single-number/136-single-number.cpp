class Solution {
public:
  int singleNumber(vector<int>& nums) {
    set<int> s(nums.begin(), nums.end());
    return 2*accumulate(s.begin(), s.end(), 0) - accumulate(nums.begin(), nums.end(), 0);
  }
};