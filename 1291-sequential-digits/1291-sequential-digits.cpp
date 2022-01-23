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

int getNextSequence(int num)
{
  if(num==0)
    return 0;
  return getNextSequence(num/10)*10 + num%10 + 1;
}

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) 
    {
      int i=1, numOfDigits = countNumberOfDigits(low);
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
          seq = getNextSequence(seq); 
        }
        cout<<"next: " <<seq<<endl;
      }
      return result;
    }
};