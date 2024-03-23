/*

Author : Saransh Bangar
Date : 23/03/2024
Problem : Reorder List
Difficulty : Medium
Problem Link : https://leetcode.com/problems/reorder-list/
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
    void reorderList(ListNode* head)
    {
        vector<int>vec1, vec2, vec;
        ListNode* temp=head;
        while (temp)
        {
            vec1.push_back(temp->val);
            vec2.push_back(temp->val);
            temp=temp->next;
        }   
        reverse(vec2.begin(), vec2.end()); 
        temp=head;
        for (int i=0;i<vec1.size()/2;i++)
        {
            vec.push_back(vec1[i]);
            vec.push_back(vec2[i]);
        }
        if (vec1.size()%2==1)
        {
            for (int i=0;i<vec.size();i++)
            {
                temp->val=vec[i];
                temp=temp->next;
            }
            temp->val=vec1[(vec1.size()/2)];
        }
        else
        {
            for (int i=0;i<vec1.size();i++)
            {
                temp->val=vec[i];
                temp=temp->next;
            }
        }
    }
};
