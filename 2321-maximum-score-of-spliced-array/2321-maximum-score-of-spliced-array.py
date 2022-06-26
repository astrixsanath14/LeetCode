class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int sum = 0, maxSum = INT_MIN;
    for(int i = 0; i < nums.size(); i++)
    {
      sum += nums[i];
      maxSum = max(maxSum, sum);
      if(sum < 0)
        sum = 0;
    }
    return maxSum;
  }  
  
  int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), sum1 = 0, sum2 = 0;
    vector<int> aMinusB(n), bMinusA(n);
    for(int i=0; i<n; i++)
    {
      sum1 += nums1[i];
      sum2 += nums2[i];
      
      aMinusB[i] = nums1[i] - nums2[i];
      bMinusA[i] = nums2[i] - nums1[i];
    }
    int ans = max(sum1, sum2);
    return max(ans,max(sum1 + maxSubArray(bMinusA), sum2 + maxSubArray(aMinusB)));
  }
};