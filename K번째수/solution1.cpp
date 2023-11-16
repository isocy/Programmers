#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> sorted_array(array.size());
    
    for (const vector<int> &command: commands) {
        partial_sort_copy(array.begin() + command[0] - 1, array.begin() + command[1],
                          sorted_array.begin(), sorted_array.end());
        answer.push_back(sorted_array[command[2] - 1]);
    }
    
    return answer;
}