/*

Author : Manas Rawat 
Date : 06/03/2024
Problem : Linked List Cycle
Difficulty : Easy 
Problem Link : https://leetcode.com/problems/linked-list-cycle/description/
Video Solution : NA

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return 0;

        ListNode * slow = head;
        ListNode * fast = head -> next;

        while(fast) {
            if(fast == slow)
                return 1;
            
            slow = slow -> next;
            fast = fast -> next ? (fast -> next) -> next : fast -> next;
        }

        return 0;
    }
};
