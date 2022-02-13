class Solution {
    public long minimumRemoval(int[] beans) {
      long sum = 0, n=beans.length, minVal = Long.MAX_VALUE;
      Arrays.sort(beans);
      for(int i=0;i<n;i++)
        sum+=beans[i];
      for(int i=0;i<n;i++)
      {
        long removals = sum - beans[i] * (n-i);
        minVal = Math.min(minVal, removals);
      }
      return minVal;
    }
}