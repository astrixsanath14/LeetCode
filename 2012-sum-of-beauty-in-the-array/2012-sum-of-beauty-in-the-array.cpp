class Solution {
public:
  int sumOfBeauties(vector<int>& nums) {
    int ans = 0, n = nums.size(), prefixMax = nums[0];
    vector<int> suffixMin(n);
    suffixMin[n-1] = nums[n-1];
    for(int i=n-2;i>=0;i--)
      suffixMin[i] = min(nums[i], suffixMin[i+1]);
    for(int i=1;i<n-1;i++)
    {
      if(prefixMax < nums[i] && nums[i] < suffixMin[i+1])
        ans+=2;
      else if(nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
        ans++;
      prefixMax = max(nums[i], prefixMax);
    }
    return ans;
  }
};