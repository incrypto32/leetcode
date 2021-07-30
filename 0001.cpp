// Two Sum
// https://leetcode.com/problems/two-sum/

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSumHashMap(vector<int> &nums, int target)
    {
        unordered_map<int,int> m;
        for (int i=0;i<nums.size();i++){
                m.insert({nums[i],i});
            if(m.find(target-nums[i])!=m.end()){
                return {m[target-nums[i]],i};
            }
        
        }
        return {};
    }

    vector<int> twoSumBruteForce(vector<int> &nums, int target)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }

        return {};
    }
};

void printVector(vector<int> v)
{
    for (auto &it : v)
    {
        cout << it<<" ";
    }
    cout << endl;
}

int main()
{
    Solution sol;
    vector<int> v = {1, 2, 3, 4, 5, 6};
    vector<int> res = sol.twoSumBruteForce(v, 12);
    vector<int> res2 = sol.twoSumHashMap(v,12);
    // printVector(res);
    printVector(res2);
    return 0;
}