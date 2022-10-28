class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int minWindowSum = INT_MAX, windowSum = 0, n = cardPoints.size();
        // cout<<"Sum: "<<sum<<"\n";
        for(int i=0;i<n; i++)
        {
            windowSum += cardPoints[i];
            if(i >= n-k)
            {
                windowSum -= cardPoints[i-(n-k)];
                // cout<<windowSum<<"\n";
                minWindowSum = min(minWindowSum, windowSum);
            }
            else
                minWindowSum = windowSum;
        }
        return sum - (minWindowSum == INT_MAX ? 0 : minWindowSum);
    }
};