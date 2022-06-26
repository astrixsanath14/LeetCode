class Solution {
  public int countHousePlacements(int n) {
    int first = 1, second = 1, total = 0, mod = (int)1e9+7;
    for(int i=1;i<=n;i++)
    {
      total = (first + second)%mod;
      second = first;
      first = total;
    }
    return (int)(1L * total * total % mod);
  }
}

 // public int countHousePlacements(int n) {
 //        int a = 1, b = 1, c = 2, mod = (int)1e9 + 7;
 //        for (int i = 0; i < n; ++i) {
 //            c = (a + b) % mod;
 //            a = b;
 //            b = c;
 //        }
 //        return (int)(1L * b * b % mod);
 //    }