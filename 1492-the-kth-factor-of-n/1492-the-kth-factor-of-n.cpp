class Solution {
public:
  int kthFactor(int n, int k) {
    if(n==1)
      return k==1 ? 1 : -1;
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
      if(k<=count/2)
        return factors[k-1];
      cout<<"k: "<<k<<" "<<" n: "<<n<<" count: "<<count<<"\n";
      int ind = count - k;
      return n/factors[ind];
    }
    return -1;
  }
};