void printVectorContents(vector<int>& arr)
{
  for(int val: arr)
  {
    cout<<val<<" ";
  }
  cout<<endl;
}

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
      int n = prices.size();
      vector<int> suffixMax(n);
      vector<int> profitsSuffix(n);
      suffixMax[n-1] = prices[n-1];
      profitsSuffix[n-1]=0;
      for(int i=n-2;i>=0;i--)
      {
        suffixMax[i] = max(prices[i],suffixMax[i+1]);
        profitsSuffix[i] = max(profitsSuffix[i+1],suffixMax[i+1] - prices[i]);
      }
      
      vector<int> prefixMin(n);
      vector<int> profitsPrefix(n);
      prefixMin[0] = prices[0];
      profitsPrefix[0]=0;
      for(int i=1;i<n;i++)
      {
        prefixMin[i] = min(prices[i],prefixMin[i-1]);
        profitsPrefix[i] = max(profitsPrefix[i-1],prices[i] - prefixMin[i-1]);
      }
      int maxProfit = 0;
      for(int i=1;i<n-1;i++)
      {
        maxProfit = max(maxProfit, profitsPrefix[i]+profitsSuffix[i+1]);
      }
      printVectorContents(profitsSuffix);
      printVectorContents(profitsPrefix);
      return max(maxProfit,profitsSuffix[0]);
    }
};