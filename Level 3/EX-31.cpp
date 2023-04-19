#include <string>
#include <vector>

using namespace std;

bool map[101][101][2] = {false};
int N;

bool check_build(int x, int y, int a) {
    if(a == 0) {
        if(y == 0) return true;
        if(y > 0 && map[x][y - 1][0]) return true;
        if(x > 0 && map[x - 1][y][1]) return true;
        if(y < N && map[x][y][1]) return true;
    }
    else {
        if(y > 0 && map[x][y - 1][0]) return true;
        if(x < N && y > 0 && map[x + 1][y - 1][0]) return true;
        if(x > 0 && x < N && map[x - 1][y][1] && map[x + 1][y][1]) return true;
    }
    
    return false;
}

bool check_remove(int x, int y, int a) {
    map[x][y][a] = false;
    
    if(a == 0) {
        if(y < N && map[x][y + 1][0] && !check_build(x, y + 1, 0)) return false;
        if(y < N && map[x][y + 1][1] && !check_build(x, y + 1, 1)) return false;
        if(x > 0 && y < N && map[x - 1][y + 1][1] && !check_build(x - 1, y + 1, 1)) return false;
    }
    else {
        if(map[x][y][0] && !check_build(x, y, 0)) return false;
        if(x < N && map[x + 1][y][0] && !check_build(x + 1, y, 0)) return false;
        if(x > 0 && map[x - 1][y][1] && !check_build(x - 1, y, 1)) return false;
        if(x < N && map[x + 1][y][1] && !check_build(x + 1, y, 1)) return false;
    }
    
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N = n;
    
    for(int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        if(b == 0) {
            if(!check_remove(x, y, a)) {
                map[x][y][a] = true;
            }
        }
        else {
            if(check_build(x, y, a)) {
                map[x][y][a] = true;
            }
        }
    }
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++)
            for(int k = 0; k <= 1; k++)
                if(map[i][j][k])
                    answer.push_back({i, j, k});
    }
    
    return answer;
}
