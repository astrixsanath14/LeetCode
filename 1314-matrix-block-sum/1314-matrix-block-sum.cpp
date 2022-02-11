class Solution {
public:
  vector<vector<long long>>prefixMatrix;
  int m,n;
  void createPrefixSumMatrix(vector<vector<int>>& matrix) {
    m = matrix.size();
    n = matrix[0].size();
    prefixMatrix.resize(m, vector<long long>(n,0));
    for (int i = 0; i < m; ++i)
    {
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
    row1 = max(row1, 0);
    col1 = max(col1, 0);
    row2 = min(row2, m-1);
    col2 = min(col2, n-1);
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
    // cout<<row1<<" "<<col1<<" "<<row2<<" "<<col2<<" "<<sum;
    // cout<<"\n";
    return sum;
  }
  
  vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    createPrefixSumMatrix(mat);
    for(int i=0;i<mat.size();i++)
    {
      for(int j=0;j<mat[0].size();j++)
      {
        mat[i][j] = sumRegion(i-k, j-k, i+k, j+k);
      }
    }
    return mat;
  }
};