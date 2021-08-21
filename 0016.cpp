// 14. Longest Common Prefix
// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        char c;
        string result = "";
        int i = 0;
        if (strs.size() == 0)
            return result;

        while (true)
        {

            if (i > (int)strs[0].length() - 1)
                return result;

            c = strs[0][i];
            for (int j = 0; j < strs.size(); j++)
            {
                if (i > strs[j].length() - 1 || strs[j][i] != c)
                    return result;
            }
            result += c;
            i++;
        }
    }
};
int main()
{
    Solution sol;
    vector<string> s = {"flower", "flow", "f"};
    cout << sol.longestCommonPrefix(s);
}