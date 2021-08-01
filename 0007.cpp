// 7. Reverse Integer
// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

#include <iostream>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int res = 0;
        while (x != 0)
        {
            int temp = x % 10;
            x /= 10;
            // 7 is the last digit of 2^31 -1
            // 8 is the last digit of -2^31
            // temp>7 because a number can be  greater than INT_MAX can be divided by 10 and have reminder upto 7
            // similarly with
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && temp > 7))
                return 0;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && temp < -8))
                return 0;

            res = res * 10 + temp;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    int s;
    cin >> s;
    cout << sol.reverse(s) << endl;
    return 0;
}