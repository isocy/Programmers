#include <string>
#include <vector>
#include <algorithm>


using namespace std;


bool cmp_seq(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> str_nums;
    
    for (const int &num: numbers) {
        str_nums.push_back(to_string(num));
    }
    
    sort(str_nums.begin(), str_nums.end(), cmp_seq);
    
    if (str_nums[0][0] == '0') {
        return "0";
    }
    
    for (const string &str_num: str_nums) {
        answer += str_num;
    }
    
    return answer;
}