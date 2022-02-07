class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int n = nums.size();
      vector<int> prefixMulArr(n);
      vector<int> suffixMulArr(n);
      prefixMulArr[0] = nums[0];
      suffixMulArr[n-1] = nums[n-1];
      for(int i=1;i<n;i++)
      {
        prefixMulArr[i] = nums[i];
        if(prefixMulArr[i-1])
           prefixMulArr[i] *= prefixMulArr[i-1];
      }
      
      for(int i=n-2;i>=0;i--)
      {
        suffixMulArr[i] = nums[i];
        if(suffixMulArr[i+1])
           suffixMulArr[i] *= suffixMulArr[i+1];
      }
      
      int ans = INT_MIN;
      for(int i=0;i<n;i++)
      {
          ans = max(ans, max(prefixMulArr[i],suffixMulArr[i]));
      }
      return ans;
    }
};