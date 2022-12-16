//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void generateAllSubsetSums(int ind, int currSum, vector<int>& arr, int &N, vector<int> &res)
    {
        if(ind == N)
        {
            res.push_back(currSum);
            return;
        }
        generateAllSubsetSums(ind+1, currSum, arr, N, res);
        generateAllSubsetSums(ind+1, currSum+arr[ind], arr, N, res);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> res;
        generateAllSubsetSums(0, 0, arr, N, res);
        return res;
    }
};

// 15
// 10000 10000 10000 10000 10000 10000 10000 10000 10000 10000 10000 10000 10000 10000 10000 10000 10000 10000

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends