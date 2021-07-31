
// 2. Add Two Numbers
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstringNaive(string s)
    {

        map<char, int> t;
        int res = 0;
        int temp = 0;
        int i = 0;

        while (i < s.length())
        {

            if (t.find(s[i]) != t.end())
            {
                t.clear();
                t[i] = i;
                string k = temp > res ? "temp" : "res";
                res = max(temp, res);
            }
            temp++;
            t.insert({s[i], i});
            i++;
        }

        return res > temp ? res : temp;
    }

    int lengthOfLongestSubstringOptimized(string s)
    {

        int res = 0; // result
        vector<int> lastIndex(256, -1);
        int i = 0;
        int j = 0;
        while (j < s.size())
        {
            i = max(i, lastIndex[s[j]] + 1);
            res = max(res, j - i + 1);
            lastIndex[s[j]] = j;
            cout << j << " " << i << " " << res << endl;
            j++;
        }

        return res;
    }
};

int main()
{
    string s = "pwwkew";
    Solution sol;
    cout << " hi " << endl;
    cout << sol.lengthOfLongestSubstringOptimized(s) << endl;
    return 0;
}