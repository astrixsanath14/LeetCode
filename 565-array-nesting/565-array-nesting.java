class Solution {
public:
    int arrayNesting(vector<int>& nums) {
      int maxCycleCount = INT_MIN;
      for(int i=0;i<nums.size();i++)
      {
        if(nums[i]>=0)
        {
          int pos = nums[i], cycleCount = 1, temp;
          while(pos!=i)
          {
            temp = nums[pos];
            nums[pos] = -(i+1);
            pos = temp;
            cycleCount++;
          }
          nums[pos] = -(temp+1);
          maxCycleCount = max(maxCycleCount, cycleCount);
        }
      }
      return maxCycleCount;
    }
};