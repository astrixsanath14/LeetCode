class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    //A: [1 2 3 4]
    //SM: [24 24 12 4] (res)
    //PV: 1->2->6->4
    int n = nums.size(), prefixMul = nums[0];
    vector<int> res(n);
    res[n-1] = nums[n-1];
    for(int i=n-2;i>=0;i--)
      res[i] = nums[i]*res[i+1];
    res[0] = res[1];
    for(int i=1;i<n-1;i++)
    {
      res[i] = res[i+1] * prefixMul;
      prefixMul *= nums[i];
    }
    res[n-1] = prefixMul;
    return res;
  }
};