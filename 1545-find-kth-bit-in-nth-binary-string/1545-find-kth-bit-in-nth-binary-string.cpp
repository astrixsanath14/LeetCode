class Solution {
public:
    char func(int n,int k)
    {
      cout<<n<<" "<<k<<"\n";
        if(n==1)
            return '0';
        long mid=(pow(2,n))/2;
        if(mid==k) 
            return '1';
        else if(k<mid) 
            return func(n-1,k);
        else 
            return '1' - func(n-1,pow(2,n)-k) + '0';
    }
    char findKthBit(int n, int k) 
    {
       return func(n,k);
    }
};