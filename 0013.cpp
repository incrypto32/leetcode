// https://leetcode.com/problems/roman-to-integer/
// 13. Roman to Integer
// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

#include <iostream>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int romanToInt(string s)
    {
        int res = 0;
        unordered_map<char, int> m = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},

        };

        for (int i = 0; i < s.length(); i++)
        {
            int a = m[s[i]];
            int b = m[s[i + 1]];

            printf("Encoutnered %c : %d next is %c : %d\n", s[i], a, s[i + 1], b);
            if (i + 1 != s.length() && (b == a * 5 || b == a * 10))
            {
                res = res - m[s[i]];
            }
            else
            {
                res = res + m[s[i]];
            }
            printf("%d\n", res);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string s;
    cin >> s;
    cout << sol.romanToInt(s);
}