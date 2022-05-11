#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct pos {
    int x;
    int y;
    int cost;
    int dir;
}pos;

int ROTATE_X[] = { -1, 0, 1, 0 };
int ROTATE_Y[] = { 0, 1, 0, -1 };

int solution(vector<vector<int>> board) {
    int answer = 987654321;
    int N = board.size();
    queue<pos> q;
    vector<vector<vector<int>>> map(4, vector<vector<int>>(N, vector<int>(N, 987654321)));
    q.push({ 0, 0, 0, 1 });
    q.push({ 0, 0, 0, 2 });
    map[1][0][0] = 0;
    map[2][0][0] = 0;
    pos cur;
    

    while (!q.empty())
    {
        cur = q.front();
        q.pop();

        if (cur.x == N - 1 && cur.y == N - 1)
        {
            answer = min(answer, cur.cost);
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int next_row = cur.x + ROTATE_Y[i];
            int next_col = cur.y + ROTATE_X[i];

            if (next_row < 0 || next_col < 0 || next_row >= N || next_col >= N || board[next_row][next_col] == 1)
                continue;

            int cur_cost;
            if (cur.dir == i)
                cur_cost = cur.cost + 100;
            else
                cur_cost = cur.cost + 600;

            if (map[i][next_row][next_col] >= cur_cost)
            {
                map[i][next_row][next_col] = cur_cost;
                q.push({ next_row, next_col, cur_cost, i });
            }

        }
    }
    return answer;
}