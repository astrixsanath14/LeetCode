int directions[5] = {0, 1, 0, -1, 0};

class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid, int i, int j) {
  int m = grid.size();
  int n = grid[0].size();
  if(i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1)
  {
    grid[i][j] = 0;
    int area = 1;
    for(int d=0;d<4;d++)
      area += maxAreaOfIsland(grid, i + directions[d], j + directions[d+1]);
    // cout<<i<<" "<<j<<" "<<area<<"\n";
    return area;
  }
  return 0;
}
  
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0;
    int m = grid.size();
    int n = grid[0].size();
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
        maxArea = max(maxArea, maxAreaOfIsland(grid, i, j));
      }
    }
    return maxArea;
  }
};

/*

[[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
[[0,0,0,0,0,0,0,0]]
[[1,1],[1,0]]
[[1,1,1],[1,0,0]]
[[0,1,1],[1,1,0]]

*/