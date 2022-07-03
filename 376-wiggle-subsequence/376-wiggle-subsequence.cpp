int getSign(int val)
{
  if(val == 0)
    return 0;
  return val/(abs(val));
}

class Solution {
public:
  int wiggleMaxLength(vector<int>& nums) {
    if(nums.size() == 1)
      return 1;
    vector<int> signs;
    int signCount = 0;
    for(int i=1;i<nums.size();i++)
    {
      int currSign = getSign(nums[i] - nums[i-1]);
      if(currSign == 0)
        continue;
      if(signCount == 0)
      {
        signs.push_back(currSign);
      }
      else if(signs[signCount-1] != currSign)
      {
        signs.push_back(currSign);
      }
      signCount = signs.size();
    }
    
    return signCount+1;
  }
};

/*

1 7 4 9 2 7
6 -3 5 -7 5

1 17 5 10 13 15 10 5 16 8
16 -12 5 3 2 -5 -5 11 -8

1 3 3 1
2 0 -2

[1,7,4,9,2,5]
[1,17,5,10,13,15,10,5,16,8]
[1,2,3,4,5,6,7,8,9]
[0]
[1]
[0,0]
[1,3,3,1]
*/