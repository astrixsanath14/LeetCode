class Solution {
public:
    int getMaxLen(vector<int>& nums) {
      int temp=1, n=nums.size(), lastPos = 0, maxLenPos=0;
      for(int i=0;i<n;i++){
        if(nums[i]!=0)
        {
          temp *= (nums[i]>0?1:-1);
          if(temp>0)
          {
            maxLenPos = max(maxLenPos, i - lastPos + 1);
          }
        }
        else{
          temp = 1;
          lastPos = i+1;
        }
      }
      temp = 1;
      lastPos = n-1;
      for(int i=n-1;i>=0;i--){
          if(nums[i]!=0)
          {
            temp *= (nums[i]>0?1:-1);
            if(temp>0)
            {
              maxLenPos = max(maxLenPos, lastPos - i + 1);
            }
          }
          else{
            temp = 1;
            lastPos = i-1;
          }
        }
      return maxLenPos;
    }
};