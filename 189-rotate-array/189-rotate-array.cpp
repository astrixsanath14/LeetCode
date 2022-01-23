void reverseTheVector(vector<int>& nums, int n, int start, int end)
{
  for(int i=start;i<(start + end)/2;i++)
    {
      int temp = nums[i];
      nums[i] = nums[start+end-i-1];
      nums[start+end-i-1] = temp;
    }
}

void printVectorContents(vector<int>& arr)
{
  for(int val: arr)
  {
    cout<<val<<" ";
  }
  cout<<endl;
}

class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
      int n = nums.size();
      k=k%n;
      printVectorContents(nums);
      reverseTheVector(nums, n, 0, n-k);
      printVectorContents(nums);
      reverseTheVector(nums, n, n-k, n);
      printVectorContents(nums);
      reverseTheVector(nums, n, 0, n);
      printVectorContents(nums);
    }
};