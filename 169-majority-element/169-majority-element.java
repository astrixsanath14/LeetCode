class Solution {
  public int majorityElement(int[] nums) {
    int counter = 0, majority=-1;
    for(int i=0;i<nums.length;i++)
    {
      if(counter==0){
        counter=1;
        majority=nums[i];
      }
      else
        counter += nums[i]==majority?1:-1;
    }
    return majority;
  }
}