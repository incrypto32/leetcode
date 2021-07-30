
// 2. Add Two Numbers
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

#include <iostream>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void addArray(ListNode &l, int arr[], int n)
{

    ListNode *l2 = &l;
    for (int i = 0; i < n; i++)
    {

        l2->val = arr[i];
        l2->next = i == n - 1 ? nullptr : new ListNode();

        l2 = l2->next;
    }
}

void printList(ListNode &l)
{

    ListNode *p = &l;

    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }
}

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *out = new ListNode(0), *p = out;

        int carry = 0;

        while (l1 || l2 || carry)
        {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = (sum / 10);
            p->val = sum % 10;
            p->next = (((l1 ? l1->next != nullptr : false) || (l2 ? l2->next != nullptr : false)) || carry) ? new ListNode() : nullptr;
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }

        return out;
    }
};

int main()
{

    ListNode l1, l2, *l3;
    Solution sol;

    int arr[] = {3, 4, 2};
    int arr2[] = {4, 6, 5};

    int n1 = sizeof(arr) / sizeof(arr[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    ;
    addArray(l1, arr, n1);
    addArray(l2, arr2, n2);
    l3 = sol.addTwoNumbers(&l1, &l2);

    printList(*l3);
    return 0;
}