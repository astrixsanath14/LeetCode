#define ull unsigned long long int
ull M = pow(10,9) + 7;
class Solution 
{
public:
  int pow(ull a, ull b, ull m){
    int ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % m;
        b /= 2;
        a = ((ull)a*a) % m;
    }
    return ans;
  }
  
  int sumSubseqWidths(vector<int>& arr) 
  {
    int n=arr.size();
    sort(arr.begin(),arr.end());
    ull totalSum = 0;
    ull prefixSum[n], ps = 1;
    ull suffixSum[n], ss = n-2;
    prefixSum[0] = arr[0];
    suffixSum[n-1] = arr[n-1];
    for(int i=1;i<n;i++)
    {
      prefixSum[ps] = prefixSum[ps-1] + arr[ps];
      suffixSum[ss] = suffixSum[ss+1] + arr[ss];
      ps++;
      ss--;
    }
    ps = 0;
    ss = n-1;
    ull powers = 1;
    for(int i=0;i<n;i++)
    {
      totalSum=(totalSum+(suffixSum[ss--] - prefixSum[ps++]) * (powers))%M;
      powers = (powers*2)%M;
    }
      return totalSum%M;
    }
};