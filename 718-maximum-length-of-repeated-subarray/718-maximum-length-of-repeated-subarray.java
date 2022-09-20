//Bottom - Up
class Solution {
  public void printArr(int arr[])
  {
    for(int i=0; i<arr.length; i++)
      System.out.print(arr[i] + " ");
    System.out.println();
  }
  public int findLength(int[] nums1, int[] nums2) {
    int m = nums1.length;
    int n = nums2.length;
    int[] dp = new int[n];
    int ans = 0;
    for(int i=0; i<m; i++)
    {
      for(int j=n-1; j>=0; j--)
      {
        if(nums1[i] == nums2[j])
        {
          dp[j] = 1;
          if(i > 0 && j > 0)
          {
            dp[j] = 1 + dp[j-1];
          }
        }
        else
        {
          dp[j] = 0;
        }
        // System.out.println(i + " " + j);
        // printArr(dp);
        ans = Math.max(ans, dp[j]);
      }
    }
    return ans;
  }
}