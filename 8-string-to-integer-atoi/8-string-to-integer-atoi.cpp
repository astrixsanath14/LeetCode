int offset = 48;
bool isNum(char c)
{
    c -= offset;
    return c>=0 && c<=9;
}
class Solution {
public:
    int myAtoi(string s) {
        int result = 0;
        bool isPlusSignRead = false;
        bool isNegative = false;
        bool isNumberRead = false;
        bool isHyphenRead = false;
        bool isLeadingSpaceOver = false;
        cout<<INT_MIN<<endl;
        cout<<INT_MAX<<endl;

        for(char c : s)
        {
            if(c!=' ')
            {
                isLeadingSpaceOver = true;
            }
            else if(isLeadingSpaceOver)
            {
               break;
            }
            if(isNum(c))
            {
                int val = (c-offset);
                isNumberRead = true;
                if(!isNegative)
                {
                    if((long)result*10 + val > INT_MAX)
                    {
                        result = INT_MAX;
                        break;
                    }   
                }
                else
                {
                    if(((long)result*10 - val) < INT_MIN)
                    {
                        result = INT_MIN;
                        break;
                    }
                    val *= -1;
                }
                result = result*10 + val;
                isLeadingSpaceOver = true;
            }
            else
            {
                if(isNumberRead)
                    break;
                if(c=='+' && !isPlusSignRead && !isHyphenRead)
                {
                    isPlusSignRead = true;
                    continue;
                }
                if(c=='-' && !isHyphenRead && !isPlusSignRead)
                {
                    result*=-1;
                    isHyphenRead = true;
                    isNegative = !isNegative;
                    continue;
                }
                else if(c == ' '  && !isLeadingSpaceOver)
                {
                    continue;
                }
                break;
            }
            
        }
        return result;
    }
};