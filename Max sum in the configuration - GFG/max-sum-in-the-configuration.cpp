// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int A[],int N)
{
    //Your code here
    int prefixSum[N], suffixSum[N];
    prefixSum[0] = A[0];
    suffixSum[N-1] = A[N-1];
    int sum = 0;
    for(int i=1;i<N;i++)
    {
        prefixSum[i] = prefixSum[i-1] + A[i];
        sum += A[i]*i;
    }
    for(int i=N-2;i>=0;i--)
    {
        suffixSum[i] = suffixSum[i+1] + A[i];
    }
    int maxDiff = 0;
    for(int k=1;k<N;k++)
    {
        int diff = k * (prefixSum[N-k-1]) - (N-k) * suffixSum[N-k];
        maxDiff = max(maxDiff, diff);
    }
    return sum + maxDiff;
}