#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    
    int answer = 0;
    
    while (true) {
        if (answer >= citations[answer]) {
            break;
        }
        answer++;
    }
    
    return answer;
}