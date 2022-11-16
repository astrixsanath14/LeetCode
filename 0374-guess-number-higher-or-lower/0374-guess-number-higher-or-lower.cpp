/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    long long guessNumber(long long n) {
        long long left = 0, right = n, mid=-1;
        while(left<=right)
        {
            mid = (left+right)/2;
            long long guessResult = guess(mid);
            if(!guessResult)
                return mid;
            if(guessResult>0)
                left = mid+1;
            else
                right = mid-1;
        }
        return mid;
    }
};