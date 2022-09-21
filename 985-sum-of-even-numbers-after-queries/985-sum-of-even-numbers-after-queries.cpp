#include<bits/stdc++.h>

class Solution {
public:
  vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    int sum = accumulate(begin(nums), end(nums), 0, [](int sum, int x) {
            return x%2==0 ? sum + x : sum; });
    
    int q = queries.size();
    vector<int> result(q);
    for(int i=0;i<q;i++)
    {
      int ind = queries[i][1];
      int val = queries[i][0];
      if(nums[ind]%2==0)
        sum -= nums[ind];
      nums[ind]+=val;
      if(nums[ind]%2==0)
        sum+=nums[ind];
      result[i] = sum;
    }
    return result;
  }
};