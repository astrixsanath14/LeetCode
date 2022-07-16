#define MOD (int)(1E9+7)
int directions[5] = {0,1,0,-1,0};
class Solution {
public:
  int findPaths(int &m, int& n, vector<vector<vector<int>>>& grid, int i, int j, int& maxMove, int moves) {
    if(moves > maxMove)
      return 0;
    // cout<<i<<" "<<j<<"\n";
    if(i>=0 && i<m && j>=0 && j<n)
    {
      if(grid[moves][i][j] != -1)
        return grid[moves][i][j];
      int numOfPaths = 0;
      for(int d=0;d<4;d++){
        numOfPaths = (numOfPaths + findPaths(m, n, grid, i + directions[d], j + directions[d+1], maxMove, moves+1))%MOD;
      }
      // cout<<i<<" "<<j<<" "<<numOfPaths<<"\n";
      return grid[moves][i][j] = numOfPaths;
    }
    return moves <= maxMove;
  }
  
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    vector<vector<vector<int>>> grid(maxMove + 1, vector<vector<int>> (m + 1, vector<int> (n + 1, -1)));
    return findPaths(m, n, grid, startRow, startColumn, maxMove, 0);
  }
};