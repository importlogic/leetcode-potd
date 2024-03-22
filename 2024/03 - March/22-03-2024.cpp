/*

Author : Manas Rawat 
Date : 22/03/2024
Problem : Palindrome Linked List
Difficulty : Easy 
Problem Link : https://leetcode.com/problems/palindrome-linked-list/description/
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
    bool isPalindrome(ListNode* head) {
        ListNode * left = head;

        function<bool(ListNode *)> traverse = [&](ListNode * right) -> bool {
            if(!right)
                return 1;

            bool ans = traverse(right -> next);
            if(!ans or left -> val != right -> val)
                return 0;

            left = left -> next;
            return 1;
        };

        return traverse(head);
    }
};
