#include <string>
#include <vector>

using namespace std;

bool visited[12][12] = { false, };
int out = 0, N;

bool check(int row, int column)
{
    for (int i = 0; i < N; i++)
        if (visited[row][i] == true)
            return false;

    for (int i = 0; i < N; i++)
        if (visited[i][column] == true)
            return false;

    for (int i = row, j = column; i >= 0 && j < N; i--, j++)
        if (visited[i][j] == true)
            return false;

    for (int i = row, j = column; i < N && j < N; i++, j++)
        if (visited[i][j] == true)
            return false;

    for (int i = row, j = column; i >= 0 && j >= 0; i--, j--)
        if (visited[i][j] == true)
            return false;

    for (int i = row, j = column; i < N && j >= 0; i++, j--)
        if (visited[i][j] == true)
            return false;

    return true;
}

void dfs(int row, int column, int queen)
{
    if (queen == N)
    {
        out++;
        return;
    }

    for (int j = 0; j < N; j++)
    {
        if (check(row, j))
        {
            visited[row][j] = true;
            dfs(row + 1, j, queen + 1);
            visited[row][j] = false;
        }
    }
}

int solution(int n) {
    int answer = 0;
    N = n;

    dfs(0, 0, 0);

    answer = out;

    return answer;
}