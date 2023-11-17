#include <string>
#include <vector>
#include <algorithm>


using namespace std;

bool cmp_citation(int a, int b) {
    return a > b;
}

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), cmp_citation);
    
    int answer = 0;
    
    while (true) {
        if (answer >= citations[answer]) {
            break;
        }
        answer++;
    }
    
    return answer;
}