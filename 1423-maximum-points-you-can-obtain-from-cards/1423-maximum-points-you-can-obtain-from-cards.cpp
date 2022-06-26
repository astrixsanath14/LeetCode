class Solution {
public:
  int maxScore(vector<int>& cardPoints, int k) {
    long long maxPoints = 0, noOfCards = cardPoints.size(), prefixSum = 0;
    vector<long long> suffixSum(noOfCards);
    suffixSum[noOfCards-1] = cardPoints[noOfCards-1];
    for(int i=noOfCards-2;i>=noOfCards-k;i--)
      suffixSum[i] = cardPoints[i] + suffixSum[i+1];
    maxPoints = suffixSum[noOfCards-k];
    for(int i=0;i<k-1;i++)
    {
      prefixSum += cardPoints[i];
      maxPoints = max(maxPoints, prefixSum + suffixSum[noOfCards-(k-(i+1))]);
    }
    maxPoints = max(maxPoints, prefixSum + cardPoints[k-1]);
    return maxPoints;
  }
};