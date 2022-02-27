class Solution {
public:
    bool canCompleteTrip(unordered_set<int>& times, unordered_map<long long,long long>& busCountPerTime, long long currTime, int totalTrips)
    {
      if(currTime<1)
        return false;
      long long totalTripsCovered = 0;
      // cout<<"currTime:: "<<currTime<<"\n";
      for(long long time:times)
      {
        // cout<<"time: "<<time<<"\n";
        long long tripsCoveredByCurrBus = (currTime/time)*busCountPerTime[time];
        // cout<<"tripsCoveredByCurrBus: "<<tripsCoveredByCurrBus<<"\n";
        totalTripsCovered+=tripsCoveredByCurrBus;
        if(totalTripsCovered>=totalTrips)
          break;
      }
      // cout<<"Total tripsCovered: "<<totalTripsCovered<<"\n";
      return totalTripsCovered>=totalTrips;
    }
  
  bool canCompleteTrip(vector<int>& times, long long currTime, int totalTrips)
    {
      if(currTime<1)
        return false;
      long long totalTripsCovered = 0;
      // cout<<"currTime:: "<<currTime<<"\n";
      for(long long time:times)
      {
        // cout<<"time: "<<time<<"\n";
        long long tripsCoveredByCurrBus = currTime/time;
        // cout<<"tripsCoveredByCurrBus: "<<tripsCoveredByCurrBus<<"\n";
        totalTripsCovered+=tripsCoveredByCurrBus;
        if(totalTripsCovered>=totalTrips)
          break;
      }
      // cout<<"Total tripsCovered: "<<totalTripsCovered<<"\n";
      return totalTripsCovered>=totalTrips;
    }
  
    long long minimumTime(vector<int>& times, int totalTrips) {
      // unordered_set<int> busTimes(times.begin(), times.end());
      long long minTimeOfBus = INT_MAX;
      long long minTripsToComplete;
      unordered_map<long long,long long> busCountPerTime;
      for(int time:times){
        busCountPerTime[time]++;
        if(minTimeOfBus > time)
          minTimeOfBus = time;
      }
      minTripsToComplete = totalTrips * minTimeOfBus;
      // cout<<"minTripsToComplete: "<<minTripsToComplete<<"\n";
      long long leastTripTime = 1,mostTripTime = minTripsToComplete;
      while(leastTripTime<=mostTripTime)
      {
        long long mid = (leastTripTime + mostTripTime) / 2;
        // if(canCompleteTrip(busTimes, busCountPerTime, mid, totalTrips))
        // {
        //   if(!canCompleteTrip(busTimes, busCountPerTime, mid-1, totalTrips))
        //     return mid;
        //   mostTripTime = mid-1;
        // }
        // else
        // {
        //   leastTripTime = mid+1;
        // }
        
        if(canCompleteTrip(times, mid, totalTrips))
        {
          if(!canCompleteTrip(times, mid-1, totalTrips))
            return mid;
          mostTripTime = mid-1;
        }
        else
        {
          leastTripTime = mid+1;
        }
      }
      return -1;
    }
};

/*
time = [1,2,3], totalTrips = 10
1) [1,0,0] - 1
2) [2,1,0] - 3
3) [3,1,1] - 5
4) [4,2,1] - 7
5) [5,2,1] - 8
6) [6,3,2] - 11 -- ans
7) [7,3,2] - 12

time = [1,1,1], totalTrips = 10
1) [1,1,1] - 3
2) [2,2,2] - 6
3) [3,3,3] - 9
4) [4,4,4] - 12 -- ans

time = [1,2,3,4,5], totalTrips = 10
1) [1,0,0,0,0] - 1
2) [2,1,0,0,0] - 3
3) [3,1,1,0,0] - 6
4) [4,2,1,1,0] - 8
5) [5,2,1,1,1] - 10 -- ans
*/