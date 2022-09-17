#define limit (long)(1e9+7)
class Solution {
public:
  long long pascalComb(int a, int b)
  {
    // cout<<a<<" "<<b<<"\n";
    long long pascalTriangle[a+1][a+1];
    for(int row=0; row<=a; row++)
    {
      for(int col=0;col<=row; col++)
      {
        if(col == 0 || col == row)
        {
          pascalTriangle[row][col] = 1;
        }
        else
        {
          pascalTriangle[row][col] = (pascalTriangle[row-1][col-1] + pascalTriangle[row-1][col]) % limit;
        }
        // cout<<pascalTriangle[row][col]<<" ";
      }
      // cout<<"\n";
    }
    return pascalTriangle[a][b];
  }
  int numberOfWays(int startPos, int endPos, int k) {
    if(endPos < startPos){
      swap(endPos, startPos);
    }
    int usefulSteps = endPos - startPos;
    int uselessSteps = k-usefulSteps;
    // cout<<"uselessSteps: "<<uselessSteps<<" usefulSteps: "<<usefulSteps<<"\n";
    if(usefulSteps > k || (uselessSteps)%2)
      return 0;
    //k = usefulSteps + uselessSteps
    
    //noOfWays = permutation((a)(usefulSteps + uselessSteps/2 in one direction) + (b)(uselessSteps/2 in other direction))
    //permutations(a,b) = (a+b)!/((a!) * (b!))
    //nCr = (n!)/((r!) * (n-r)!)
    //say, n = a+b & r = a -> b = n-a -> b = n-r
    //permutations(a,b) = (n)!/((r!) * (n-r!)) = (a+b)Ca or (a+b)Cb
    int direction1Steps = usefulSteps + uselessSteps/2;
    int direction2Steps = uselessSteps/2;
    return pascalComb(direction1Steps + direction2Steps,direction1Steps);
  }
};