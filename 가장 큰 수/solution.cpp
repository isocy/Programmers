#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp_pair(const pair<string, int> &a, const pair<string, int> &b) {
    if (a.second == b.second) {
        if (a.first.size() + b.first.size() == 5) {
            if (a.first.size() == 2) {
                return a.first[0] < a.first[1];
            }
            else {
                return a.first[0] > a.first[1];
            }
        }
        else {
            return true;
        }
    }
    else {
        return a.second > b.second;
    }
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<pair<string, int>> pairs;
    
    int zero_cnt = 0, thousand_cnt = 0;
    bool is_zero = true;
    string str_num;
    int num_padded;
    
    for (const int &num : numbers) {
        if (num == 0) {
            zero_cnt++;
            continue;
        }
        if (num == 1000) {
            thousand_cnt++;
            continue;
        }
        
        is_zero = false;
        
        str_num = to_string(num);
        if (str_num.size() == 1) {
            num_padded = num * 100 + (str_num[0] - 48) * 11;
        }
        else if (str_num.size() == 2) {
            num_padded = num * 10 + (str_num[0] - 48);
        }
        else {
            num_padded = num;
        }
        
        pairs.emplace_back(str_num, num_padded);
    }
    
    if (is_zero) {
        return "0";
    }
    
    sort(pairs.begin(), pairs.end(), cmp_pair);
    
    for (const auto &[str_num, num_padded] : pairs) {
        answer += str_num;
    }
    for (int i = 0; i < thousand_cnt; i++) {
        answer += "1000";
    }
    for (int i = 0; i < zero_cnt; i++) {
        answer += '0';
    }
    
    return answer;
}