//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int dx[] = {0,1};
int dy[] = {1,0};

class Solution {
public:
    void printPath(vector<pair<int, int>> &currPath)
    {
        for(pair<int, int> coord : currPath)
        {
            cout<<coord.first << " " << coord.second<<", ";
        }
        cout<<"\n";
    }
    
    bool canMoveHere(int &x, int &y, int &n, vector<vector<int>> &matrix, int &noOfHops)
    {
        return (x == n-1 && y == n-1) || ( x>=0 && x<n && y>=0 && y<n && matrix[x][y]!=0);
    }
    
    bool getShortestDistance(int x, int y, int &n, vector<vector<int>> &matrix, vector<pair<int, int>> &currPath, vector<pair<int, int>> &minPath)
    {
        if(x == n-1 && y == n-1)
        {
            if(minPath.size() == 0 || currPath.size() < minPath.size())
            {
                minPath = currPath;
                // printPath(currPath);
                // cout<<"Found valid path!"<<"\n";
            }
            return true;
        }
        for(int step=1; step<=matrix[x][y]; step++)
        {
            for(int i=0;i<2;i++)
            {
                int newX = x + step*dx[i];
                int newY = y + step*dy[i];
                if(canMoveHere(newX, newY, n, matrix, step))
                {
                    currPath.push_back({newX, newY});
                    // cout<<"Trying path from "<<x<<" "<<y<<" to "<<newX<<" "<<newY<<"\n";
                    bool gotValidPathFromThisDirection = getShortestDistance(newX, newY, n, matrix, currPath, minPath);
                    if(gotValidPathFromThisDirection)
                    {
                        return true;
                    }
                    currPath.pop_back();
                }
            }
        }
        return false;
    }
    
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	   int n = matrix.size();
	   if(n == 1)
	   {
	       return vector<vector<int>>(1, vector<int>(1,1));
	   }
	   vector<pair<int, int>> currPath, minPath;
	   getShortestDistance(0, 0, n, matrix, currPath, minPath);
	   if(minPath.size()>0)
	   {
	       vector<vector<int>> res(n, vector<int>(n, 0));
	       int prevX = 0, prevY = 0;
	       for(pair<int, int> coord:minPath)
	       {
	           res[coord.first][coord.second] = 1;
	           prevX = coord.first;
	           prevY = coord.second;
	       }
	       res[0][0] = 1;
	       return res;
	   }
	   return vector<vector<int>>(1, vector<int>(1,-1));
	}
};

/*
2 1 0 0
3 0 0 1
0 1 0 1
0 0 0 1

1 0 0 0
1 0 0 1
0 0 0 1
0 0 0 1

4
2 0 1 4
0 1 0 3
0 0 2 1
3 2 4 0

4
3 2 4 0
2 0 0 3
3 4 3 2
3 0 2 4
*/


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends