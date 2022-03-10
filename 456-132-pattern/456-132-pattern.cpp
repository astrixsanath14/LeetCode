class Solution {
public:
  void printPGE(vector<int> &pge, vector<int> &nums, int &n)
  {
    for(int i=0;i<n;i++)
      cout<<i<<":"<<nums[i]<<" ";
    cout<<"\n";
    for(int i=0;i<n;i++)
      cout<<i<<":"<<(pge[i] == -1 ? -1 : nums[pge[i]])<<" ";
    cout<<"\n\n";
  }
  
  void generatePreviousGreatestElement(vector<int> &pge, vector<int> &nums, int &n)
  {
    stack<int> remaining;
    remaining.push(n-1);
    for(int i = n-2; i>=0; i--)
    {
      while(!remaining.empty() && nums[i] > nums[remaining.top()])
      {
        pge[remaining.top()] = i;
        remaining.pop();
      }
      remaining.push(i);
    }
    // printPGE(pge, nums, n);
  }
  
  bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    vector<int> pge(n, -1), preMin(n);
    preMin[0] = nums[0];
    generatePreviousGreatestElement(pge, nums, n);
    for(int i=1; i<n; i++){
      
      // if(pge[i]!=-1)
      //   cout<<preMin[pge[i]] << " " <<  nums[i]<<"\n";

      if(i>1 && pge[i]!=-1 && preMin[pge[i]] < nums[i]){
        return true;
      }
      
      preMin[i] = min(preMin[i-1], nums[i]);
    }
    return false;
  }
};