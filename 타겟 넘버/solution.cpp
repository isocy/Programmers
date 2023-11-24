#include <iostream>
#include <string>
#include <numeric>
#include <vector>

using namespace std;


struct problem {
    vector<int> numbers;
    int target;

    problem(vector<int>, int);
};

problem::problem(vector<int> numbers, int target) {
    this->numbers = numbers;
    this->target = target;
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    if (target > sum || (sum - target) % 2 == 1) {
        return answer;
    }
    
    target = (sum - target) / 2;
    
    
    vector<problem> problems;
    problems.emplace_back(numbers, target);
    
    int temp_front, temp_target;
    while (!problems.empty()) {
        vector<int> &temp_nums = problems.back().numbers;
        
        temp_front = temp_nums[0];
        vector<int> partial_nums(temp_nums.begin() + 1, temp_nums.end());
        temp_target = problems.back().target;
        
        problems.pop_back();
        
        
        if (partial_nums.empty()) {
            if (temp_front == temp_target) {
                answer++;
            }
            continue;
        }
        
        
        if (temp_front < temp_target) {
            problems.emplace_back(partial_nums, temp_target - temp_front);
        }
        else if (temp_front == temp_target) {
            answer++;
        }
        
        problems.emplace_back(partial_nums, temp_target);
    }
    
    return answer;
}