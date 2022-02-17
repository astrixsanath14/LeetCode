
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
class Solution {
public:
  int getMaximumGold(vector<vector<int>>& grid, int currI, int currJ, int &rows, int &columns)
  {
    int maxGold = 0;
    grid[currI][currJ]*=-1;
    
    for(int p=0;p<4;p++)
      if((currI + dx[p]>=0) && (currI+dx[p]<rows) && (currJ+dy[p]>=0) && (currJ+dy[p]<columns) && (grid[currI+dx[p]][currJ+dy[p]])>0)
        maxGold = max(maxGold, getMaximumGold(grid, currI + dx[p], currJ + dy[p], rows, columns));
    
    grid[currI][currJ]*=-1;
    return maxGold + grid[currI][currJ];
  }
  
  int getMaximumGold(vector<vector<int>>& grid) {
   int maxGold = 0, m = grid.size(), n = grid[0].size();
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        if(grid[i][j]>0)
          maxGold = max(maxGold, getMaximumGold(grid, i, j, m, n));
    return maxGold;
  }
};