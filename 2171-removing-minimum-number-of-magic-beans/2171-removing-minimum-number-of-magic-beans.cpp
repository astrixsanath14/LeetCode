class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
      long long n = beans.size();
      vector<long long> pSum(n), sSum(n);
      sort(begin(beans), end(beans));
      pSum[0]=beans[0];
      for(int i=1;i<n;i++)
      {
        pSum[i]=pSum[i-1]+beans[i];
      }
      
      sSum[n-1]=beans[n-1];
      for(int i=n-2;i>=0;i--)
      {
        sSum[i]=sSum[i+1]+beans[i];
      }
      long long ans = LLONG_MAX;
      for(int i=0;i<n;i++){
        long long removals=0;
        if(i>0)
          removals += pSum[i-1];
        if(i<n-1)
          removals += sSum[i+1] - (long long)beans[i] * (n-1-i);
        ans = min(ans, removals);
      }
      return ans;
    }
};