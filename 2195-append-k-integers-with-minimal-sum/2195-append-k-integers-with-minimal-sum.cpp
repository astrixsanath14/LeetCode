
class Solution
{
public:
    long long getSumInRange(long long rangeStart, long long rangeEnd)
    {
      // cout << "start " << rangeStart << "\n";
      //   cout << "end " << rangeEnd << "\n";
        rangeStart--;
        long long sum = (rangeEnd * (rangeEnd + 1)) / 2 - (rangeStart * (rangeStart + 1)) / 2;
        // cout << "sum " << sum << "\n";
        return sum;
    }

    long long minimalKSum(vector<int> &nums, int k)
    {
        // priority_queue<long long, vector<long long>, greater<long long> > pq(nums.begin(), nums.end());
      sort(nums.begin(),nums.end());
        long long minElement = 1, sumOfKElements = 0, ind = 0, n = nums.size();
        while (k > 0)
        {
            if (ind >= n)
                break;
            long long top = nums[ind];
            // cout << "minElement: " << minElement << " top: " << top << " k: "<<k<<"\n";
            if (top != minElement)
            {
                // cout << "Yes\n";
                long long noOfElements = min((long long)k-1, (long long)(top - minElement - 1));
                // cout<<"noOfElements: "<<noOfElements<<"\n";
                long long endRange = minElement + noOfElements;
                sumOfKElements += getSumInRange(minElement, endRange);
                k -= noOfElements + 1;
                minElement = endRange + 1;
            }
            else
            {
                while (ind<n && nums[ind] == top)
                    ind++;
                minElement++;
            }
        }
        if (k > 0)
        {
            long endRange = minElement + k - 1;
            sumOfKElements += getSumInRange(minElement, endRange);
        }
        return sumOfKElements;
    }
};