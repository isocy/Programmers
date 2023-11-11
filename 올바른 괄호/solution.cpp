#include <string>
#include <iostream>

using namespace std;


bool solution(string s)
{
    bool answer = true;
    int open_cnt = 0;
    
    for (int idx = 0; idx < s.size(); idx++) {
        if (s[idx] == '(') {
            open_cnt++;
        }
        else {
            if (open_cnt == 0) {
                answer = false;
                break;
            }
            
            open_cnt--;
        }
    }
    
    if (open_cnt != 0) {
        answer = false;
    }

    return answer;
}