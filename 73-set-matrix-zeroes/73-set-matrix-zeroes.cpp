void print(vector<vector<int>>& matrix)
{
  for(int i=0;i<matrix.size();i++)
  {
    for(int j=0;j<matrix[0].size();j++)
    {
      cout<<matrix[i][j]<<" ";
    }
    cout<<"\n";
  }
  cout<<"\n";
}

class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size(), isFirstCell0 = matrix[0][0] == 0, isFirstRow0 = 0, isFirstCol0 = 0;
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(matrix[i][j] == 0)
        {
          matrix[i][0] = 0;
          matrix[0][j] = 0; 
          if(j==0)
            isFirstCol0 = 1;
          if(i==0)
            isFirstRow0 = 1;
        }
      }
    }
    for(int j=1;j<n;j++)
    {
     if(!matrix[0][j]) 
     {
       for(int i=1;i<m;i++)
         matrix[i][j] = 0;
     }
    }
    for(int i=1;i<m;i++)
    {
     if(!matrix[i][0]) 
     {
       for(int j=1;j<n;j++)
         matrix[i][j] = 0;
     }
    }
    if(isFirstCell0 || isFirstCol0)
      for(int i=0;i<m;i++)
          matrix[i][0] = 0;
    if(isFirstCell0 || isFirstRow0)
      for(int j=0;j<n;j++)
        matrix[0][j] = 0;
  }
};