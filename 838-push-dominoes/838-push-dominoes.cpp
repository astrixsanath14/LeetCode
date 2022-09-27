class Solution {
public:
  string pushDominoes(string dominoes) {
    int n = dominoes.length();
    int closestLeft[n][2], closestRight[n][2];//0-left, 1-right
    int closestLeftInd = -1, closestRightInd = -1;
    
    for(int i=n-1; i>=0; i--)
    {
      closestLeft[i][1] = closestLeftInd;
      if(dominoes[i] == 'L')
      {
        closestLeftInd = i;
      }
      closestRight[i][1] = closestRightInd;
      if(dominoes[i] == 'R')
      {
        closestRightInd = i;
      }
    }
    
    closestLeftInd = -1, closestRightInd = -1;
    for(int i=0; i<n; i++)
    {
      closestLeft[i][0] = closestLeftInd;
      if(dominoes[i] == 'L')
      {
        closestLeftInd = i;
      }
      closestRight[i][0] = closestRightInd;
      if(dominoes[i] == 'R')
      {
        closestRightInd = i;
      }
    }
    
    
    for(int i=0; i<n; i++)
    {
      if(dominoes[i]=='.'){
        int closestLeftOnItsLeft = closestLeft[i][0];
        int closestLeftOnItsRight = closestLeft[i][1];
        
        int closestRightOnItsLeft = closestRight[i][0];
        int closestRightOnItsRight = closestRight[i][1];
        // cout<<"i: "<<i<<" closestLeftOnItsLeft: "<<closestLeftOnItsLeft<<" closestLeftOnItsRight: "<<closestLeftOnItsRight<<" closestRightOnItsLeft: "<<closestRightOnItsLeft<<" closestRightOnItsRight: "<<closestRightOnItsRight<<"\n";
        
        if(closestLeftOnItsRight == -1 && closestRightOnItsLeft == -1)
        {
          continue;
        }
        else if(closestLeftOnItsRight == -1)
        {
          if(closestLeftOnItsLeft == -1 || closestRightOnItsLeft>closestLeftOnItsLeft)
          {
            dominoes[i] = 'R';
          }
        }
        else if(closestRightOnItsLeft == -1)
        {
          if(closestRightOnItsRight == -1 || closestLeftOnItsRight<closestRightOnItsRight)
          {
            dominoes[i] = 'L';
          }
        }
        else
        {
          int leftD = -1;
          if(closestLeftOnItsLeft == -1 || closestRightOnItsLeft>closestLeftOnItsLeft)
          {
            leftD = i - closestRightOnItsLeft;
          }
          
          int rightD = -1;
          if(closestRightOnItsRight == -1 || closestLeftOnItsRight<closestRightOnItsRight)
          {
            rightD = closestLeftOnItsRight - i;
          }
          if(leftD == rightD)
          {
            continue;
          }
          else if(leftD == -1 || rightD == -1){
            if(rightD==-1)
            {
              dominoes[i] = 'R';
            }
            else
            {
              dominoes[i] = 'L';
            }
           }
            else if(leftD<rightD)
            {
              dominoes[i] = 'R';
            }
            else
            {
              dominoes[i] = 'L';
            }
          // cout<<"leftD: "<<leftD<<" rightD: "<<rightD<<"\n";
        }
      }
    }
    return dominoes;
  }
};