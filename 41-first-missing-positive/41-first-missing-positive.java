class Solution {
  public int firstMissingPositive(int[] A) {
    int n = A.length;
    for(int i = 0; i < n; ++ i)
        while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
        {
          // Collections.swap(Arrays.asList(A), i, A[i]-1);
          int pos = A[i]-1;
          int temp = A[i];
          A[i] = A[pos];
          A[pos] = temp;
        }
    for(int i=0;i<n;i++)
      System.out.println(A[i]);
    for(int i = 0; i < n; ++ i)
        if(A[i] != i + 1)
            return i + 1;

    return n + 1;
  }
}