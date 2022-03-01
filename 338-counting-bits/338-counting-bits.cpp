class Solution {
public:
  vector<int> countBits(int n) {
    if(n==0)
      return vector<int>(1,0);
    vector<int> ans(n+1);
    ans[0] = 0;
    ans[1] = 1;
    int powerOf2 = 2, ind=2; 
    // cout<<"n: "<<n<<"\n";
    while(ind <= n)
    {
      int counter = 1;
      while(ind < powerOf2 && ind <=n)
      {
        // cout<<"ind: "<<ind<<" counter: "<<counter<<"\n";
        ans[ind++] = 1 + ans[counter++];
      }
      if(ind>n)
        break;
      ans[ind++] = 1;
      powerOf2<<=1;
    }
    return ans;
  }
};
/*
0  --> 0000 --> 0
1  --> 0001 --> 1
2  --> 0010 --> 1
3  --> 0011 --> 2
4  --> 0100 --> 1
5  --> 0101 --> 2
6  --> 0110 --> 2
7  --> 0111 --> 3
8  --> 1000 --> 1
9  --> 1001 --> 2
10 --> 1010 --> 2
11 --> 1011 --> 3
12 --> 1100 --> 2
13 --> 1101 --> 3
14 --> 1110 --> 3
15 --> 1111 --> 4
16 --> 10000 --> 1
17 --> 10001 --> 2
18 --> 10010 --> 2
19 --> 10100 --> 2
20 --> 11000 --> 2
21 --> 11001 --> 3
22 --> 11010 --> 3
23 --> 11011 --> 4
24 --> 11100 --> 3
25 --> 11101 --> 4
26 --> 11110 --> 4
27 --> 11111 --> 5
*/