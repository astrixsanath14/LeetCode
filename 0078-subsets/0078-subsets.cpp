//Recursion
class Solution {
public:
    void subsets(int i, vector<int>& nums, int j, vector<int> &tempSubset, vector<vector<int>> &result) {
        if(i==nums.size())
        {
            vector<int> subset(j);
            for(int t=0;t<j;t++)
                subset[t] = tempSubset[t];
            result.push_back(subset);
            return;
        }
        tempSubset[j] = nums[i++];
        subsets(i, nums, j+1, tempSubset, result);
        subsets(i, nums, j, tempSubset, result);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset(nums.size());
        vector<vector<int>> result;
        subsets(0, nums, 0, subset, result);
        return result;
    }
};


// // Cascading technique
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//       int n = nums.size(), count=1;
//       vector<vector<int>> ans(1);
//       for(int num:nums)
//       {
//         vector<vector<int>> curNumCombo = ans;
//         for(vector<int> curAns : ans)
//         {
//           vector<int> temp = curAns;
//           temp.push_back(num);
//           curNumCombo.push_back(temp);
//         }
//         ans = curNumCombo;
//       }
//       return ans;
//     }
// };