class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
      int n = nums.size(), sum = nums[0];
      vector<int> prefixSum(n);
      prefixSum[0] = nums[0];
      for(int i=1;i<n;i++)
      {
        sum+=nums[i];
        prefixSum[i] = nums[i] + prefixSum[i-1];
      }
      vector<int> result(n);
      for(int i=1;i<n-1;i++)
      {
        int suffixSum = sum - prefixSum[i];
        result[i] = i*nums[i] - prefixSum[i - 1] + suffixSum - nums[i]*(n-1-i);
      }
      result[0] = sum - nums[0] - (n-1)*nums[0];
      result[n-1] = (n-1) *nums[n-1] - prefixSum[n-2];
      return result;
    }
};