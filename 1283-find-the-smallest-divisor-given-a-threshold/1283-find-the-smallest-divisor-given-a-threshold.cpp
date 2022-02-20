class Solution {
public:
  bool canGetBelowThreshold(vector<int>& nums, int divisor, int threshold)
  {
    if(divisor<=0)
      return false;
    int sum = 0;
    for(int val : nums)
    {
      int div = ceil((float)val/divisor);
      if(sum+div>threshold)
        return false;
      sum += div;
    }
    if(sum<=threshold)
      return true;
    return false;
  }
  
  int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1, high = *max_element(nums.begin(), nums.end());
    while(low<=high)
    {
      int mid = (low+high)/2;
      bool isBelowThreshold = canGetBelowThreshold(nums, mid, threshold);
      if(isBelowThreshold)
      {
        if(!canGetBelowThreshold(nums, mid-1, threshold))
          return mid;
        high = mid-1;
        canGetBelowThreshold(nums, mid, threshold);
      }
      else
      {
        low = mid+1;
      }
    }
    return 0;
  }
};