class Solution {
public:
    bool replaced = false;
    int maximum69Number (int num) {
        if(num==0)
            return 0;
        int digit = num%10;
        num/=10;
        num = maximum69Number(num);
        if(digit == 6 && !replaced)
        {
            digit = 9;
            replaced = true;
        }
        return num*10+digit;
    }
};