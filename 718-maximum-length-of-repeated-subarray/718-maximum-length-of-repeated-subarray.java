class Solution {
public:
  
  int lors(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>>& dp)
  {
    if(i == -1 || j == -1)
    {
      return 0;
    }
    if(dp[i][j] != -1)
    {
      return dp[i][j];
    }
    int res;
    if(nums1[i] == nums2[j])
    {
      dp[i][j] = (1 + lors(nums1, nums2, i-1, j-1, dp));
    }
    else
    {
      dp[i][j] = 0;
    }
    
    lors(nums1, nums2, i-1, j, dp);
    lors(nums1, nums2, i, j-1, dp);
    
    return dp[i][j];
  }
  
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    lors(nums1, nums2, m-1, n-1, dp);
    int result = -1;
    for(int i = 0; i<m; i++)
    {
      for(int j=0;j<n;j++)
      {
        result = max(result, dp[i][j]);
      }
    }
    return result;
  }
};