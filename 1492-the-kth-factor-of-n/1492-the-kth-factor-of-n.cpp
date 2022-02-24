class Solution {
public:
  int kthFactor(int n, int k) {
    int count = 0;
    vector<int> factors;
    for(int i=1;i*i<=n;i++)
    {
      if(n%i==0){
        factors.push_back(i);
        count+=2;
        count-=(n/i==i);
      }
    }
    if(count>=k)
    {
      if(k<=count/2 && count/2>0)
        return factors[k-1];
      return n/factors[count - k];
    }
    return -1;
  }
};