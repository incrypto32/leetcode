// Median of two sorted arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double findMedian(vector<int> &vec)
    {
        int s = vec.size();
        if (s % 2 == 0)
        {
            return vec[(s - 2) / 2] + vec[s / 2];
        }
        else
        {
            return vec[(s - 1) / 2];
        }
    }

    int binarySearch(vector<int> &main, vector<int> &ref, int i, int j)
    {
        int mid;
        int l = 0, r = main.size() - 1;

        while (r >= l)
        {
            mid = l + (r - l) / 2;
        }
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();

        if (m == 0)
        {
            return findMedian(nums1);
        }
        else if (n == 0)
        {
            return findMedian(nums1);
        }

        int index = m < n ? binarySearch(nums1, nums2, 0, m) : binarySearch(nums2, nums1, 0, n);

        return index;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {1, 3};
    vector<int> v2 = {2};
    cout << sol.findMedianSortedArrays(v1, v2);
    return 0;
}