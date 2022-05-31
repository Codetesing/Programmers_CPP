#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> d;
bool visited[8] = { false };
int out = 0;

void DFS(int cur, int cnt)
{
    for(int i = 0; i < d.size(); i++)
        if (!visited[i] && cur >= d[i][0])
        {
            visited[i] = true;
            DFS(cur - d[i][1], cnt + 1);
            visited[i] = false;
        }

    out = max(out, cnt);
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;

    d = dungeons;

    DFS(k, 0);

    answer = out;

    return answer;
}