class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size(),i,j,counter=0,layer=0;
    vector<int> spiral(m*n);
    while(counter!=m*n)
    {
      i = layer, j = layer;
      while(j<n-layer && counter!=m*n)
      {
        spiral[counter++] = matrix[i][j++];
        cout<<spiral[counter-1]<<" ";
      }
      j--;
      i++;
      while(i<m-layer && counter!=m*n)
      {
        spiral[counter++] = matrix[i++][j];
        cout<<spiral[counter-1]<<" ";
      }
      i--;
      j--;
      while(j>=layer && counter!=m*n)
      {
        spiral[counter++] = matrix[i][j--];
        cout<<spiral[counter-1]<<" ";
      }
      j++;
      i--;
      while(i>layer && counter!=m*n)
      {
        spiral[counter++] = matrix[i--][j];
        cout<<spiral[counter-1]<<" ";
      }
      layer++;
    }
    cout<<"\n";
    return spiral;
  }
};