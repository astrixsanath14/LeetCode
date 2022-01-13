bool comp(vector<int>& balloon1, vector<int>& balloon2)
{
    return (balloon1[1] < balloon2[1]);
}

void printVector(vector<vector<int>>& balloons)
{
    for(vector<int> balloon : balloons)
    {
        cout<<balloon[0] << " " << balloon[1] << endl;
    }
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& balloons) 
    {
        int arrowCount = 1;
        // cout<<"Before: \n";
        // printVector(balloons);
        sort(balloons.begin(), balloons.end(), comp);
        // cout<<"After: \n";
        // printVector(balloons);
        int previouslyShortArrowIndex = balloons[0][1];
        // cout << "balloons.size(): " << balloons.size();
        for(int i = 1; i < balloons.size(); ++i)
        {
            // cout<<" here " << i;
            vector<int> balloon = balloons[i];
            if(balloon[0] <= previouslyShortArrowIndex)
            {
                continue;
            }
            arrowCount++;
            previouslyShortArrowIndex = balloon[1];
        }
        return arrowCount;
    }
};