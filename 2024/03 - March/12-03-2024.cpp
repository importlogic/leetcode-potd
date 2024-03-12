/*
Author : Saransh Bangar
Date : 12/03/2024
Problem : Remove Zero Sum Consecutive Nodes from Linked List
Difficulty : Medium 
Problem Link : https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/
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
    ListNode* removeZeroSumSublists(ListNode* head)
    {
        ListNode* front = new ListNode(0, head);
        ListNode* current = front;
        int prefixSum = 0;
        unordered_map<int, ListNode*> prefixSumToNode;
        prefixSumToNode[0] = front;

        while (current != nullptr)
        {
            prefixSum += current->val;
            prefixSumToNode[prefixSum] = current;
            current = current->next;
        }

        prefixSum = 0;
        current = front;

        while (current != nullptr)
        {
            prefixSum += current->val;
            current->next = prefixSumToNode[prefixSum]->next;
            current = current->next;
        }
        return front->next;
    }
};
