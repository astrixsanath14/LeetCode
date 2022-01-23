void reverseTheVector(vector<int>& nums, int n, int start, int end)
{
  for(int i=start;i<(start + end)/2;i++)
    {
      int temp = nums[i];
      nums[i] = nums[start+end-i-1];
      nums[start+end-i-1] = temp;
    }
}

class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
      int n = nums.size();
      k=k%n;
      reverseTheVector(nums, n, 0, n-k);
      reverseTheVector(nums, n, n-k, n);
      reverseTheVector(nums, n, 0, n);
    }
};