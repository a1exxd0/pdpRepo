#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
    stack<int> s;
public:
    int evalRPN(vector<string>& tokens) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int first;
        int second;
        for (auto t : tokens){
            if (t != "-" && t != "+" && t != "*" && t != "/"){
                s.push(stoi(t));
            } else{
                first = s.top(); s.pop();
                second = s.top(); s.pop();
                switch (t[0]){
                    case '+':
                        s.push(first+second);
                        break;
                    case '*':
                        s.push(first * second);
                        break;
                    case '-':
                        s.push(second - first);
                        break;
                    case '/':
                        s.push(second / first);
                        break;
                    default:
                        return 0;
                }
            }
        }
        return s.top();
    }
};