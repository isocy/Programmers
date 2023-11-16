#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> sorted_array(array.size());

    int command_cnt = commands.size();

    for (int command_idx = 0; command_idx < command_cnt; command_idx++) {
        vector<int> command = commands[command_idx];
        partial_sort_copy(array.begin() + command[0] - 1, array.begin() + command[1],
                          sorted_array.begin(), sorted_array.begin() + command[2]);
        answer.push_back(sorted_array[command[2] - 1]);
    }

    return answer;
}