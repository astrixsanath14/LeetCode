class Solution {
  public boolean searchMatrix(int[][] matrix, int target) {
    int m = matrix.length;
    int n = matrix[0].length;
    int row = 0, col = n-1;
    while(true)
    {
      while(col>=0 && target<matrix[row][col])
        col--;
      if(col<0)
        break;
      System.out.println(col);
      while(row<m && target>matrix[row][col])
        row++;
      if(row>=m)
        break;
      System.out.println(row);
      if(target == matrix[row][col])
        return true;
    }
    return false;
  }
}