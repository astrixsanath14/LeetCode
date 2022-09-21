#include<bits/stdc++.h>

class Solution {
public:
  vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
//     auto is_even = [](int i) { return i % 2 == 0; };
//     auto evens = nums | views::filter(is_even);
    
    std::vector<int> foo = {25,15,5,-5,-15};
    std::vector<int> evens;
    // copy only even numbers:
    std::copy_if (nums.begin(), nums.end(), back_inserter(evens), [](int i){return i%2==0;} );
    int sum = accumulate(begin(evens), end(evens), 0);
    
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