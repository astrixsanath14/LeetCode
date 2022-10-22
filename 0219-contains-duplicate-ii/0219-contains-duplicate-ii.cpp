class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> windowFreq;
        for(int i=0;i<nums.size();i++)
        {
            if(i-(k+1)>=0)
                windowFreq[nums[i-(k+1)]]--;
            windowFreq[nums[i]]++;
            if(windowFreq[nums[i]] > 1)
            {
                return true;
            }
        }
        return false;
    }
};