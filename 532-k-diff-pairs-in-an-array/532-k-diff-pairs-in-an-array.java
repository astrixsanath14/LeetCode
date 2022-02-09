class Solution {
    public int findPairs(int[] nums, int k) {
      int l=0,r=0,ans=0;
      Arrays.sort(nums);
      while(l<nums.length)
      {
        r=Math.max(l+1,r);
        //Shifting r to next pos of next number with at least k-diff
        while(r<nums.length && nums[r]-nums[l]<k)
          r++;
        if(r<nums.length && nums[r]-nums[l]==k)
          ans++;
        //Shifting l to skip duplicates
        while(l+1 < nums.length && nums[l] == nums[l+1])
          l++;
        l++;
      }
      return ans;
    }
}