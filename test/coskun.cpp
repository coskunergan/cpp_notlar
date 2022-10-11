
#include <bits/stdc++.h>
#include <cstring>

// Input: num = 1994
// Output: "MCMXCIV"
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4

using namespace std;
///////////////////////////////
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode{};
        ListNode *head = res;
        int val, carry = 0;

        while(1)
        {
            val = l1->val + l2->val;
            if(carry)
            {
                val += 1;
                carry = 0;
                if(val > 9)
                {
                    val -= 10;
                    carry = 1;
                }
            }
            if(val > 9)
            {
                val -= 10;
                carry = 1;
            }
            res->val = val;

            if(l1->next == nullptr && l2->next == nullptr && carry == 0)
            {
                break;
            }

            res->next = new ListNode{};
            res = res->next;

            if(l2->next != nullptr)
            {
                l2 = l2->next;
            }
            else
            {
                l2->val = 0;
            }
            if(l1->next != nullptr)
            {
                l1 = l1->next;
            }
            else
            {
                l1->val = 0;
            }
        }
        return head;
    }
};
//////////////////////////////

ListNode *prepare_list(char *arr)
{
    int index = strlen(arr);
    ListNode *l = new ListNode{arr[index - 1] - '0'};
    ListNode *head = l;
    while(--index)
    {
        l->next = new ListNode{};
        l = l->next;
        l->val = arr[index - 1] - '0';
    }
    return head;
}

int main()
{
    Solution x;
    ListNode *l1 = prepare_list((char *)"9999999");
    ListNode *l2 = prepare_list((char *)"9999");

    cout << "----------begin--------\n\n";

    ListNode *res = x.addTwoNumbers(l1, l2);

    do
    {
        cout << "(" << res->val << ")";
    }
    while((res = res->next) != nullptr);

    cout << "\n\n-----------end---------";
}