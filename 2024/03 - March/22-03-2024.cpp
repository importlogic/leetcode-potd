/*

Author : Saransh Bangar
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
    bool isPalindrome(ListNode* head)
    {
        string str="";
        while (head)
        {
            char c=head->val;
            str+=c;
            head=head->next;
        }
        string rev=str;
        reverse(rev.begin(), rev.end());
        return str==rev;
    }
};
