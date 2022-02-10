class NumMatrix {
public:
  vector<vector<long long>>prefixMatrix;
    NumMatrix(vector<vector<int>>& matrix) {
      int m = matrix.size();
      int n = matrix[0].size();
      prefixMatrix.resize(m);
      for (int i = 0; i < m; ++i)
      {
        prefixMatrix[i].resize(n);
        for(int j=0;j<n;j++)
        {
          prefixMatrix[i][j]=matrix[i][j];
          if(j>0)
            prefixMatrix[i][j]+=prefixMatrix[i][j-1];
        }
      }
      for(int i=0;i<n;i++)
      {
        for(int j=1;j<m;j++)
        {
          prefixMatrix[j][i]+=prefixMatrix[j-1][i];
        }
      }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        long long sum =  prefixMatrix[row2][col2];
        if(row1>0)
        {
          sum-=prefixMatrix[row1-1][col2];
        }
      if(col1>0)
        {
          sum-=prefixMatrix[row2][col1-1];
        }
      if(row1>0 && col1>0)
      {
        sum+=prefixMatrix[row1-1][col1-1];
      }
      return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */