#include<vector>
#include <queue>

using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int row = maps.size();
    int col = maps[0].size();
    
    int INITIAL_COST = 2;
    
    queue<pair<int, int>> points({{0, 0}});
    maps[0][0] = INITIAL_COST;
    int cur_x, cur_y;
    while (!points.empty()) {
        cur_x = points.front().first;
        cur_y = points.front().second;
        points.pop();
        
        if (cur_y < col - 1 && maps[cur_x][cur_y + 1] == 1) {
            maps[cur_x][cur_y + 1] = maps[cur_x][cur_y] + 1;
            points.push({cur_x, cur_y + 1});
        }
        if (cur_x < row - 1 && maps[cur_x + 1][cur_y] == 1) {
            maps[cur_x + 1][cur_y] = maps[cur_x][cur_y] + 1;
            points.push({cur_x + 1, cur_y});
        }
        if (cur_y > 0 && maps[cur_x][cur_y - 1] == 1) {
            maps[cur_x][cur_y - 1] = maps[cur_x][cur_y] + 1;
            points.push({cur_x, cur_y - 1});
        }
        if (cur_x > 0 && maps[cur_x - 1][cur_y] == 1) {
            maps[cur_x - 1][cur_y] = maps[cur_x][cur_y] + 1;
            points.push({cur_x - 1, cur_y});
        }
    }
    
    int res = maps[row - 1][col - 1];
    if (res == 1) {
        return -1;
    }
    
    return res - (INITIAL_COST - 1);
}