#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    // Function which return string by concatenating it.
    string repeat(int n, string s)
    {
        // Copying given string to temporary string.
        string s1 = "";
        n = n < 0 ? 0 : n;
        for (int i = 0; i < n; i++)
            s1 += s; // Concatenating strings
        // cout << n << " " << s1.length() << endl;
        return s1;
    }

    string convertFormatted(string s, int n)
    {

        string res = "";

        for (int j = 0; j < n; j++)
        {
            int i = 0;
            while (i < s.length())
            {
                res = res + s[i + j] + " " + repeat((n - 2) - j, "  ");
                if (j != 0 && j != n - 1 && i + 2 * (n - 1) - j < s.length())
                    res = res + s[i + 2 * (n - 1) - j] + " ";

                res += repeat(j - 1, "  ");
                i += 2 * (n - 1);
            }
            res += '\n';
        }

        return res;
    }

    string convert(string s, int n)
    {

        string res = "";

        if (n == 1)
        {
            return s; 
        }

        for (int j = 0; j < n; j++)
        {
            int i = 0;
            while (i + j < s.length())
            {
                res = res + s[i + j];
                if (j != 0 && j != n - 1 && i + 2 * (n - 1) - j < s.length())
                    res = res + s[i + 2 * (n - 1) - j];
                i += 2 * (n - 1);
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;

    cout << sol.convert("AB", 1);
}