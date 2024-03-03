/*

Author : Manas Rawat 
Date : 03/03/2024
Problem : Remove Nth Node From End of List
Difficulty : Medium 
Problem Link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int pos = -1;

        function<void(ListNode *)> traverse = [&](ListNode * node) {
            if(!node)
                return;

            traverse(node -> next);
            ++pos;

            if(pos == n) {
                node -> next = node -> next -> next;
            }
        };

        traverse(head);
        ++pos;

        return pos == n ? head -> next : head;
    }
};
