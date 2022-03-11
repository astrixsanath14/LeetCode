class Solution {
public:
  void printVector(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
        cout<<matrix[i][j]<<" ";
      }
      cout<<"\n";
    }
    cout<<"\n";
  }
  
  int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size(), sum = matrix[0][0];
    // printVector(matrix);
    for(int i=1;i<m;i++)
    {
      for(int j=1;j<n;j++)
      {
        if(matrix[i][j])
        {
          matrix[i][j] += min(min(matrix[i-1][j-1],matrix[i-1][j]), matrix[i][j-1]);
          sum+=matrix[i][j];
        }
        if(i==1)
          sum+=matrix[0][j];
        if(j==1)
          sum+=matrix[i][0];
      }
    }
    // printVector(matrix);
    return sum;
  }
};