// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    void NBitBinary(int &N, string &s, int noOfOnes, int index, vector<string>& result)
    {
        if(index == N){
            result.push_back(s);
            return;
        }
        // s[index] = '1';
        s.push_back('1');
        NBitBinary(N, s, noOfOnes + 1, index+1, result);
        if(noOfOnes > index - noOfOnes){
            s[index] = '0';
            NBitBinary(N, s, noOfOnes, index+1, result);
        }
        s.pop_back();
    }
	vector<string> NBitBinary(int &N)
	{
	    vector<string> result;
	   // string ans(N, '1');
	    string ans = "1";
	    int noOfOnes = 1, index = 1;
	    NBitBinary(N, ans, noOfOnes, index, result);
	    return result;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}  // } Driver Code Ends