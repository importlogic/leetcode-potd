/*

Author : Manas Rawat 
Date : 20/03/2024
Problem : Merge In Between Linked Lists
Difficulty : Medium 
Problem Link : https://leetcode.com/problems/merge-in-between-linked-lists/description
Video Solution : NA

*/


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
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode * b_head = list2;
        ListNode * b_tail = list2;

        while(b_tail -> next != nullptr)
            b_tail = b_tail -> next;

        ListNode * cur = list1;

        int index = 0;

        while(index != a - 1)
            cur = cur -> next,++index;

        ListNode * last = cur;
        cur = cur -> next;
        ++index;
        last -> next = b_head;

        while(index != b)
            cur = cur -> next, ++index;

        b_tail -> next = cur -> next;

        return list1;
    }
};
