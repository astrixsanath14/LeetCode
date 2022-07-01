bool compare(vector<int> a, vector<int> b)
{
  return a[1] > b[1];
}
class Solution {
public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), compare);
    int res = 0;
    for(vector<int> boxType : boxTypes)
    {
      cout<<boxType[0]<<" "<<boxType[1]<<endl;
      if(!truckSize)
        break;
      int truckSizeForType = min(truckSize, boxType[0]);
      res += boxType[1] * truckSizeForType;
      truckSize -= truckSizeForType;
    }
    return res;
  }
};