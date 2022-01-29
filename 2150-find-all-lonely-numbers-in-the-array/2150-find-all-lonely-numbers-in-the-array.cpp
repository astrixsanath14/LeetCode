class Solution {
public:
    vector<int> findLonely(vector<int>& nums) 
    {
      long freq[1000002] = {0};
      for(int i:nums)
      {
        freq[i]++;
      }
      vector<int> lonelyNumbers;
      for(int i:nums)
      {
        if(freq[i]==1 && (i == 0 || freq[i-1] == 0) && freq[i+1] == 0)
        {
          lonelyNumbers.push_back(i);
        }
      }
      return lonelyNumbers;
    }
};