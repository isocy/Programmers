#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int progress_size = progresses.size();
    int progress_idx = 0;
    int day_elapsed, streak;

    while (progress_idx < progress_size) {
        day_elapsed = (100 - progresses[progress_idx] + (speeds[progress_idx] - 1)) / speeds[progress_idx];
        streak = 1;

        progress_idx++;
        while (progress_idx < progress_size &&
               progresses[progress_idx] + speeds[progress_idx] * day_elapsed >= 100) {
            progress_idx++;
            streak++;
        }

        answer.push_back(streak);
    }

    return answer;
}