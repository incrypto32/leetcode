#include <iostream>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int sign = 1;
        int res = 0;
        int i = s.find_first_not_of(' ');
        if (s.empty() || i == -1)
            return 0;
        if (s[i] == '+' || s[i] == '-')
        {
            sign = s[i++] == '+' ? 1 : -1;
        }

        while (isdigit(s[i]))
        {
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && ((s[i] - '0') > INT_MAX % 10)))
                return sign > 0 ? INT_MAX : INT_MIN;
            res = res * 10 + (s[i++] - '0');
        }
        return sign * res;
    };
};

int main()
{
    Solution sol;
    cout
        << sol.myAtoi(" 42") << endl;
}