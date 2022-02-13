class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascalTriangle(numRows);
    for(int i=0;i<numRows;i++)
    {
      int colCount = i+1;
      vector<int> temp(colCount, 1);
      for(int j=1;j<colCount-1;j++)
      {
        temp[j] = pascalTriangle[i-1][j-1] + pascalTriangle[i-1][j];
      }
      pascalTriangle[i] = temp;
    }
    return pascalTriangle;
  }
};