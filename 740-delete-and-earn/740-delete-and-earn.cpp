#define MAX_COUNT (int)1E4+1

class Solution {
public:
  int deleteAndEarn(vector<int>& nums) {
    int freq[MAX_COUNT] = {0};
    int maxElement = INT_MIN;
    for(int num:nums)
    {
      maxElement = max(maxElement, num);
      freq[num] += num;
    }
    int first = 0, second = freq[1];
    
    for(int i=2;i<=maxElement;i++)
    {
      int curr = max(first + freq[i], second);
      first = second;
      second = curr;
    }
    return second;
  }
};