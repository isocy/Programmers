#include <iostream>

#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> left;
    
    for (int idx = 0; idx < s.size(); idx++) {
        if (left.empty() || left.top() != s[idx]) {
            left.push(s[idx]);
        }
        else {
            left.pop();
        }
    }
    
    return left.empty();
}