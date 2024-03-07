/*

Author : Saransh Bangar
Date : 07/03/2024
Problem : Middle of the Linked List
Difficulty : Easy 
Problem Link : https://leetcode.com/problems/middle-of-the-linked-list/description/
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
    ListNode* middleNode(ListNode* head)
    {
        ListNode* temp=head;
        int count=0;
        while (temp!=nullptr)
        {
            count++;
            temp=temp->next;
        }
        temp=head;
        int ans=count/2;
        while (ans)
        {
            temp=temp->next;
            ans--;
        }
        return temp;
    }
};
