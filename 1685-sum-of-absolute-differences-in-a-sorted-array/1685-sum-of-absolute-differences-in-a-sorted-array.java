class Solution 
{
  public int[] getSumAbsoluteDifferences(int[] nums) 
  {
    int sum = 0, ps=0, len=nums.length;
    for(int val:nums)
      sum+=val;
    int[] res = new int[len];
    for(int i=0;i<len;i++)
    {
      res[i] = nums[i]*(i) - ps + (sum-ps-nums[i]) - nums[i]*(len-i-1);
      ps+=nums[i];
    }
    return res;
  }
}