#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isPalindromeBruteForce(int x)
    {
        string s = to_string(x);
        string temp = s;
        reverse(temp.begin(), temp.end());
        return temp == s;
    }

    bool isPalindrome(int x)
    {
        int result = 0;
        while (x > result)
        {
            result = result * 10 + x % 10;
            x /= 10;
        }

        // When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
        // For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
        // since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it.
        return x == result || x == result / 10;
    }
};

int main()
{
    Solution sol;
    int n;
    cout << "Enter the number : ";
    cin >> n;
    cout << sol.isPalindrome(n) << endl;
}