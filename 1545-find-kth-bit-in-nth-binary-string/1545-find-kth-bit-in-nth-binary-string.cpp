class Solution {
public:
  int getNextK(int n, int k){
    long len = pow(2,n), mid = len/2;
    
    cout<<n<<" "<<k<<" "<<len<<" "<<mid<<"\n";
    if(mid == k)
      return -1;
    if(k>mid)
      k = mid - (k - mid);
    return k;
  }
  char findKthBit(int n, int k) {
    if(n == 1)
      return '0';
    int nextK = getNextK(n, k);
    if(nextK == -1)
      return '1';
    if(k!=nextK){
      return '1' - findKthBit(n-1,nextK) + '0';
    }
    return findKthBit(n-1,nextK);
  }
};