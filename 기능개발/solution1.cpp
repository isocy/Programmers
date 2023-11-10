#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int day_required, day_elapsed = 0;
    
    for (int progress_idx = 0; progress_idx < progresses.size(); progress_idx++) {
        day_required = (99 - progresses[progress_idx]) / speeds[progress_idx] + 1;
        
        if (day_required > day_elapsed) {
            day_elapsed = day_required;
            answer.push_back(1);
        }
        else {
            answer.back()++;
        }
    }
    
    return answer;
}