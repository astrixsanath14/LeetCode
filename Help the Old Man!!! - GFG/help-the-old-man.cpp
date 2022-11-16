//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void shiftPile(int noOfPlates, int n, int &stepNo, int fromPlate, int midPlate, int toPlate, vector<int>& nthStep)
    {
        if(noOfPlates>0)
        {
            shiftPile(noOfPlates-1, n, stepNo, fromPlate, toPlate, midPlate, nthStep);
            stepNo++;
            if(stepNo == n)
            {
                nthStep[0] = fromPlate;
                nthStep[1] = toPlate;
            }
            // cout<<"Move plate from "<<fromPlate<<" to "<<toPlate<<"\n";
            shiftPile(noOfPlates-1, n, stepNo, midPlate, fromPlate, toPlate, nthStep);
        }
    }
    vector<int> shiftPile(int noOfPlates, int n){
        // code here
        vector<int> nthStep(2,0);
        int stepNo = 0;
        shiftPile(noOfPlates, n, stepNo, 1, 2, 3, nthStep);
        return nthStep;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends