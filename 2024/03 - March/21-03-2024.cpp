/*

Author : Saransh Bangar
Date : 21/03/2024
Problem : Reverse Linked List
Difficulty : Easy 
Problem Link : https://leetcode.com/problems/reverse-linked-list/description/
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
    ListNode* reverseList(ListNode* head)
    {
        vector<int>help;
        ListNode* temp=head;
        while (temp!=nullptr)
        {
            help.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        for (int i=help.size()-1;i>=0;i--)
        {
            temp->val=help[i];
            temp=temp->next;
        }
        return head;
    }
};
