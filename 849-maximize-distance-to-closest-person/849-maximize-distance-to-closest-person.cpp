class Solution {
public:
    int maxDistToClosest(vector<int>& seats) 
    {
      int resultLocation = INT_MIN;
      int resultLocationMinDist = INT_MIN;
      vector<int> occupiedSeatLocations;
      for(int location=0; location<seats.size(); location++)
      {
        if(seats[location] == 1)
        {
          occupiedSeatLocations.push_back(location);
        }
      }
      
      
      int firstOccupiedSeatLocation = occupiedSeatLocations[0];
      int lastOccupiedSeatLocation = occupiedSeatLocations[occupiedSeatLocations.size() - 1];
      
      if(firstOccupiedSeatLocation != 0)
      {
        occupiedSeatLocations.insert(occupiedSeatLocations.begin(), -firstOccupiedSeatLocation);
      }
      
      if(lastOccupiedSeatLocation != seats.size() - 1)
      {
        int diff = seats.size() - 1 - lastOccupiedSeatLocation;
        occupiedSeatLocations.push_back(seats.size() - 1 + diff);
      }
      
      for(int index = 0; index < occupiedSeatLocations.size()-1; index++)
      {
        int currSeatLoc = occupiedSeatLocations[index];
        int nextSeatLoc = occupiedSeatLocations[index+1];
        int numberOfSeatsInBetween = nextSeatLoc - currSeatLoc;
        if(numberOfSeatsInBetween > 1)
        {
          int minDist = numberOfSeatsInBetween/2;
          int midSeatLocation = currSeatLoc + minDist;
          if(minDist > resultLocationMinDist)
          {
            resultLocationMinDist = minDist;
            resultLocation = midSeatLocation;
          }
        }
      }
      return resultLocationMinDist;
    }
};