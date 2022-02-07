class Solution {
    public int maxProduct(int[] nums) {
      int maxProduct = Integer.MIN_VALUE;
      int temp = 1;
      for(int i=0;i<nums.length;i++)
      {
        temp = temp * nums[i];
        maxProduct = Math.max(maxProduct, temp);
        if(temp==0)
          temp=1;
      }
      temp=1;
      for(int i=nums.length-1;i>=0;i--)
      {
        temp = temp * nums[i];
        maxProduct = Math.max(maxProduct, temp);
        if(temp==0)
          temp=1;
      }
      
      return maxProduct;
    }
}