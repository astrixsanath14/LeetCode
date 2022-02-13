class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      set<int> ans;
      map<int,int> counter;
      int n = nums.size();
      
      for(int i=0;i<n;i++){
        counter[nums[i]]++;
        if(counter[nums[i]]>n/3)
          ans.insert(nums[i]);
      }
      return vector<int>(ans.begin(), ans.end());
    }
};