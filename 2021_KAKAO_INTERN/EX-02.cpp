#include <string>
#include <vector>

using namespace std;

int N = 5;
vector<vector<string>> map;

int ROTATE_X[] = { -1, 0, 0, 1 };
int ROTATE_Y[] = { 0, -1, 1, 0 };

bool visited[5][5][5] = { false };

bool DFS(int ind, int row, int col, int cnt)
{
    visited[ind][row][col] = true;

    if (cnt != 0)
    {
        if (map[ind][row][col] == 'P')
            return false;
        if (cnt == 2)
            return true;
    }
    for (int i = 0; i < 4; i++)
    {
        int next_row = row + ROTATE_X[i];
        int next_col = col + ROTATE_Y[i];

        if (next_row < 0 || next_col < 0 || next_row >= N || next_col >= N || visited[ind][next_row][next_col])
            continue;

        if (!DFS(ind, next_row, next_col, cnt + 1))
            return false;
    }

    return true;
}

bool IS_OK(int ind)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (map[ind][i][j] == 'X')
                visited[ind][i][j] = true;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (map[ind][i][j] == 'P')
            {
                if (!DFS(ind, i, j, 0))
                    return false;
            }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    map = places;

    for (int i = 0; i < N; i++)
    {
        if (IS_OK(i))
            answer.push_back(1);
        else
            answer.push_back(0);
    }

    return answer;
}