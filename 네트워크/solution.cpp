#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> is_visited(n, false);
    
    for (int com_idx = 0; com_idx < n; com_idx++) {
        if (is_visited[com_idx]) {
            continue;
        }
        
        answer++;
        
        vector<int> to_visit({com_idx});
        int cur_idx;
        while (!to_visit.empty()) {
            cur_idx = to_visit.back();
            to_visit.pop_back();
            
            if (is_visited[cur_idx]) {
                continue;
            }
            is_visited[cur_idx] = true;
            
            vector<int> &edges = computers[cur_idx];
            for (int idx = 0; idx < n; idx++) {
                if (edges[idx]) {
                    to_visit.push_back(idx);
                }
            }
        }
    }
    
    return answer;
}