class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      map<int,int> counter;
      int minVal = INT_MAX, maxVal = INT_MIN;
      for(int num:nums)
      {
        if(num>0)
        {
          counter[num]++; 
          minVal = min(minVal, num);
          maxVal = max(maxVal, num);
        }
      }
      for(int i=1;i<minVal;i++)
        if(!counter[i])
          return i;
      for(int i=minVal;i<maxVal;i++)
        if(!counter[i])
          return i;
      return maxVal+1;
    }
};