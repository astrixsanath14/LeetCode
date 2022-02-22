class Solution {
    public int titleToNumber(String columnTitle) {
        int res=0, offset = 'A'-1, l = columnTitle.length(), charCount = 26;
    for(int i=0;i<l;i++)
      res += Math.pow(charCount, i) * (columnTitle.charAt(l-i-1) - offset);
    return res;
    }
}