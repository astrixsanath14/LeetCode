class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    int dx[]={1,0,-1,0}, dy[]={0,1,0,-1}, count = 1, row=0, col=0, directionIndex = 0;
    vector<vector<int>> spiral = vector(n, vector<int>(n, 0));
    while(count<=n*n)
    {
      int done = 0;
      while(col>=0 && col<n && row<n && row>=0 && spiral[row][col]==0)
      {
        // cout<<"done::: row: "<<row<<" col: "<<col<<" count: "<<count<<"\n";
        spiral[row][col] = count++;
        col+=dx[directionIndex];
        row+=dy[directionIndex];
        done++;
      }
      col-=dx[directionIndex];
      row-=dy[directionIndex];
      directionIndex = (directionIndex+1)%4;
      col+=dx[directionIndex];
      row+=dy[directionIndex];
      // cout<<"next direction::: "<<directionIndex<<" row: "<<row<<" col: "<<col<<" count: "<<count<<"\n";
    }
    return spiral;
  }
};