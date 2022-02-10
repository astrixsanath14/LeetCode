class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
          if(n<2)
            return 0;
          int maxNum = *max_element(nums.begin(), nums.end()), minNum = *min_element(nums.begin(),nums.end());
      if(maxNum == minNum)
          return 0;
      int numberOfElementsInBetweenMinAndMax = n - 2;
      //Nums: 10.....20
      //N:6
      //Min gaps: 10 12 14 16 18 20
      //Max diff = 2
      //Therefore for any combo of elements with arr having 10 as Min and 20 as Max
      //and N=6, the min val. of max consecutive diff. is 2
      //Thus, we may split the 
      int gap = (maxNum-minNum)/(n-1);
      gap += (maxNum - minNum)%(n-1)!=0;
      vector<int> minBucket(n, INT_MAX), maxBucket(n, INT_MIN);
      for(int i=0;i<n;i++)
      {
        int bucketNoForElement = (nums[i] - minNum)/gap;
        minBucket[bucketNoForElement] = min(minBucket[bucketNoForElement],nums[i]);
        maxBucket[bucketNoForElement] = max(maxBucket[bucketNoForElement],nums[i]);
      }
      int ans = INT_MIN, prev = INT_MIN;
      // for(int i=0;i<n;i++)
      // {
      //   cout<<minBucket[i]<<" "<<maxBucket[i]<<endl;
      // }
      for(int i=0;i<n;i++)
      {
        if(minBucket[i] == INT_MAX)
          continue;
        if(prev != INT_MIN)
        {
          ans = max(ans, minBucket[i]-prev);
        }
        prev = maxBucket[i];
      }
      return ans;
    }
};