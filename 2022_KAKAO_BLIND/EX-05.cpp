#include <string>
#include <vector>

using namespace std;

vector<vector<int>> graph(18, vector<int>());
vector<int> visited;

int max_num = 0;

void DFS(int cur, int lamp, int wolf)
{
    if (lamp == wolf)
    {
        if (lamp > max_num)
            max_num = lamp;
        return;
    }

    visited[cur] = -1;
    for(int i = 0; i < graph[cur].size(); i++)

}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;

    visited = info;

    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    DFS(0, 1, 0);

    return answer;
}