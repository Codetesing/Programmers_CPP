#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> map;
bool visited[501][501][4] = { false };

int NEXT_ROW[] = { 0, 1, 0, -1 };
int NEXT_COL[] = { -1, 0, 1, 0 };
int N, M;

int CHANGE(char A, int dir)
{
    if (A == 'R')
    {
        if (dir == 0) return 1;
        if (dir == 1) return 2;
        if (dir == 2) return 3;
        if (dir == 3) return 0;
    }
    else
    {
        if (dir == 0) return 3;
        if (dir == 1) return 0;
        if (dir == 2) return 1;
        if (dir == 3) return 2;
    }
}

int DFS(int row, int col, int dir, int len)
{
    if (visited[row][col][dir])
        return len;

    visited[row][col][dir] = true;

    int next_row = row;
    int next_col = col;
    int next_dir = dir;

    if (map[row][col] != 'S')
        next_dir = CHANGE(map[row][col], dir);

    next_row += NEXT_ROW[next_dir];
    next_col += NEXT_COL[next_dir];

    if (next_row == -1)
        next_row = N - 1;
    if (next_row == N)
        next_row = 0;
    if (next_col == -1)
        next_col = M - 1;
    if (next_col == M)
        next_col = 0;

    return DFS(next_row, next_col, next_dir, len + 1);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;

    map = grid;
    N = grid.size();
    M = grid[0].size();

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            for (int k = 0; k < 4; k++)
            {
                int len = DFS(i, j, k, 0);
                if (len != 0)
                    answer.push_back(len);
            }

    sort(answer.begin(), answer.end());

    return answer;
}