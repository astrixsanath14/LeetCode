class Solution {
public:
  int gcd(int a, int b)
  {
    if(b==0)
      return a;
    return gcd(b,a%b);
  }
  
  int minOperations(vector<int>& nums, vector<int>& numsDivide) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int gcdNums = *max_element(numsDivide.begin(), numsDivide.end());
    for(int i:numsDivide)
    {
      gcdNums = gcd(gcdNums, i);
    }
    sort(nums.begin(), nums.end());
    int deletionCount = 0;
    for(int num:nums){
      if(gcdNums%num == 0)
        return deletionCount;
      if(num>gcdNums)
        break;
      deletionCount++;
    }
    return -1;
  }
};