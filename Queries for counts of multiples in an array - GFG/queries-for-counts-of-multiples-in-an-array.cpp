// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> countMultiples(int arr[], int q[], int n, int m) ;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n >> m;
        int q[m], arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (i = 0; i < m; i++) cin >> q[i];

        vector<int> answering = countMultiples(arr, q, n, m);
        for (auto it : answering) cout << it << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends

vector<int> countMultiples(int A[], int Q[], int N, int M) {
    int maxVal = INT_MIN;
    for(int i=0;i<N;i++)
        maxVal = max(maxVal, A[i]);
    int pre[maxVal+1] = {0};
    for(int i=0;i<N;i++)
        pre[A[i]]++;
    for(int i=1;i<=maxVal;i++)
    {
        for(int j=i+i;j<=maxVal;j+=i)
        {
            pre[i]+=pre[j];
        }
    }
    vector<int> ans(M);
    for(int i=0;i<M;i++)
        if(Q[i]<=maxVal)
            ans[i] = pre[Q[i]];
        else
            ans[i] = 0;
    return ans;
}