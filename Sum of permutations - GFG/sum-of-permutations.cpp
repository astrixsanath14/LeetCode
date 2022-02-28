// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


long long getSum(int [],int n);
main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		cout<<getSum(a,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this method */
long long getSum(int A[],int n)
{
    //Your code here
    long long nFact = 1, len = n, ones = 1, sum = 0, mod = 1000000007;
    while(--len){
        nFact *= len;
        ones = (ones*10)+1;
    }
    for(int i=0;i<n;i++)
        sum += A[i];
    // cout<<nFact<<" "<<ones<<" "<<sum<<"\n";
    return (sum * nFact * ones)  % mod;
}