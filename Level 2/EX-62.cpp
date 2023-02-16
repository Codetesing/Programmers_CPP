#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int row, col, cnt;
int ROTATE_X[] = { -1, 0, 0, 1 };
int ROTATE_Y[] = { 0, -1, 1, 0 };
vector<string> m;
bool visited[100][100] = { false };

void DFS(int r, int c) {
    visited[r][c] = true;
    cnt += m[r][c] - '0';

    for (int i = 0; i < 4; i++) {
        int next_row = r + ROTATE_X[i];
        int next_col = c + ROTATE_Y[i];

        if (next_row < 0 || next_row >= row || next_col < 0 || next_col >= col)
            continue;

        if(!visited[next_row][next_col] && m[next_row][next_col] != 'X')
            DFS(next_row, next_col);
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    row = maps.size();
    col = maps[0].size();
    m = maps;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (!visited[i][j] && maps[i][j] != 'X') {
                cnt = 0;
                DFS(i, j);
                answer.push_back(cnt);
            }

    if (answer.empty())
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());

    return answer;
}
