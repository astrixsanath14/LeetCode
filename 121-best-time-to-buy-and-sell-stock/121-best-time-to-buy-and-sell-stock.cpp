class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
      int profit = 0, n=prices.size(), highestSellingPrice = prices[n-1];
      for(int i=n-2;i>=0;i--)
      {
        highestSellingPrice = max(highestSellingPrice, prices[i]);
        profit = max(profit, highestSellingPrice - prices[i]);
      }
      return profit;
    }
};