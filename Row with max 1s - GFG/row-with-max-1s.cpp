// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int row=0,col=m-1, maxCount = 0, maxRow = -1;
	    while(row<n && col >=0)
	    {
	        while(col>=0 && arr[row][col])
	        {
	            maxRow = row;
	            maxCount++;
	            col--;
	        }
	        if(col==-1)
	            return maxRow;
	        while(row<n && !arr[row][col])
	        {
	            row++;
	        }
	        if(row==n)
	            return maxRow;	        
	    }
	    return maxRow;
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends