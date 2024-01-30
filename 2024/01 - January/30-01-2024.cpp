/*

Author : Manas Rawat
Date : 30/01/2024
Problem : Evaluate Reverse Polish Notation
Difficulty : Medium
Problem Link : https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
Video Solution : NA

*/


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> val;

        for(auto i : tokens){
            if(i == "+" or i == "-" or i == "*" or i == "/"){
                int y = val.top();
                val.pop();
                int x = val.top();
                val.pop();

                if(i == "+")
                    val.push(x + y);
                else if(i == "-")
                    val.push(x - y);
                else if(i == "*")
                    val.push(x * y);
                else
                    val.push(x / y);
            }
            else{
                val.push(stoi(i));
            }
        }

        return val.top();
    }
};