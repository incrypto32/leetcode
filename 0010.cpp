#include <iostream>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int j = 0;
        int i = 0;
        int k = 0;
        while (true)
        {

            char a = s[i];
            char b = p[j];
            char c = p[j + 1];
            bool match = a == b || b == '.';
            k++;
            if (k > 6)
                return false;
            printf("a : %c   b : %c   c : %c   match : %d\n", (a == 0 ? ' ' : a), b, c, match);

            if (i >= s.length() && j >= p.length())
            {

                return true;
            }
            else if (j >= p.length())
                return false;

            if (c == '*')
                match ? i++ : j += 2, i++;
            else if (match)
            {
                i++;
                j++;
            }
            else
            {
                return false;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    string s;
    cout << sol.isMatch("ab", ".*");
    return 0;
}