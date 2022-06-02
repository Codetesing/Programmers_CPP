#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<vector<int>> G(101, vector<int>());
bool visited[101] = { false };

void DFS(vector<int> execpt, int ind, int cnt)
{
    visited[ind] = true;

    for (int i = 0; i < G[ind].size(); i++)
    {
        int next = G[ind][i];

        if (visited[next]) continue;
        if (ind == execpt[0] && next == execpt[1]) continue;
        if (ind == execpt[1] && next == execpt[0]) continue;

        DFS(execpt, next, cnt + 1);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;

    for (int i = 0; i < wires.size(); i++)
    {
        G[wires[i][0]].push_back(wires[i][1]);
        G[wires[i][1]].push_back(wires[i][0]);
    }

    for (int i = 0; i < wires.size(); i++)
    {
        DFS(wires[i], 1, 1);
        
        int group_num = 0;

        for (int j = 1; j <= n; j++)
            if (visited[j])
                group_num++;
                
        int dif = n - group_num;
        answer = min(answer, abs(group_num - dif));

        for (int j = 1; j <= n; j++)
            visited[j] = false;
        group_num = 0;
    }

    return answer;
}