
// 5. Longest Palindromic Substring
// Given a string s, return the longest palindromic substring in s
// https://leetcode.com/problems/longest-palindromic-substring/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
    bool checkPalindrome(string s)
    {
        int l = 0, h = s.length() - 1;
        while (h > l)
        {
            if (s[h] != s[l])
            {

                return false;
            }
            h--;
            l++;
        }

        return true;
    }

    string longestPalindromeBruteForce(string s)
    {
        string res = "";
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j < s.length(); j++)
            {
                string substr = s.substr(i, j - i + 1);
                if (s[i] == s[j] && substr.length() > res.length() && checkPalindrome(substr))
                {
                    res = substr;
                }
            }
        }
        return res;
    }

    string longestPalindromeExpandAroundCenterNaive(string s)
    {
        string res = "";
        for (int i = 0; i < s.size(); i++)
        {
            string s1 = expandAroundCenterSubstring(s, i, i);
            string s2 = expandAroundCenterSubstring(s, i, i + 1);
            string temp = s1.length() > s2.length() ? s1 : s2;
            res = res.length() > temp.length() ? res : temp;
        }
        return res;
    }

    string expandAroundCenterSubstring(string s, int l, int r)
    {

        string str = "";

        while (l >= 0 && r < s.size() && s[l] == s[r])
        {

            str = s.substr(l, r - l + 1);

            l--;
            r++;
        }

        return str;
    }
};
int main()
{
    Solution sol;

    cout << sol.longestPalindromeExpandAroundCenterNaive("babad") << endl;
    return 0;
}