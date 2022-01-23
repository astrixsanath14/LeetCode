int countNumberOfDigits(int num)
{
  if(num==0)
    return 0;
  return 1+countNumberOfDigits(num/10);
}

int generateFirstSequenceForCount(int count)
{
  if(count == 1)
  {
    return 1;
  }
  return generateFirstSequenceForCount(count-1)*10 + count;
}

int getNextSequenceRecursively(int num)
{
  if(num==0)
    return 0;
  return getNextSequenceRecursively(num/10)*10 + num%10 + 1;
}

int getNextSequence(int num, int count)
{
  return (num%((int)pow(10,count-1)))*10+(num%10)+1;
}

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) 
    {
      int numOfDigits = countNumberOfDigits(low);
      vector<int> result;
      int seq = generateFirstSequenceForCount(numOfDigits);
      while(seq <= high)
      {
        if(seq >= low && seq <= high)
        {
          result.push_back(seq); 
        }
        if(seq%10==9)
        {
          numOfDigits++;
          seq = generateFirstSequenceForCount(numOfDigits);
        }
        else
        {
          seq = getNextSequence(seq, numOfDigits); 
        }
      }
      return result;
    }
};