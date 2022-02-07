#define M (ull)1e9+7
#define ull unsigned long long int

class Solution {
public:
    int countOrders(int n) {
      ull ans = 1;
      for(ull i=2;i<=n;i++)
      {
        // int x = 2*i-1;
        // x*=(x+1)/2;
        // ans*=x;
        // ans%=M;
        
        long x = 2*i-1;
        ans=(ans*(x*(x+1)/2));
        ans%=M;
      }
      return ans;
    }
};