//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N) 
    { 
        if(N==1)
        return -1;
        int i = 0;
        int suffixMax[N];
        suffixMax[N-1] = A[N-1];
        for(int i=N-2; i>=0; i--)
        {
            suffixMax[i] = max(suffixMax[i+1], A[i]);
        }
        int maxDiff = 0;
        for(int i=0; i<N; i++)
        {
            int j = i+maxDiff;
            while(j<N && suffixMax[j]>=A[i])
            {
                j++;
            }
            maxDiff = max(maxDiff, j-1-i);
        }
        return maxDiff;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends