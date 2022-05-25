#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> G(51, vector<pair<int, int>>());
vector<int> node;
bool visited[51] = { false };
int cnt = 0;

void DFS(int ind, int len, int max_len)
{
    if (len > max_len)
        return;

    visited[ind] = true;
    node.push_back(ind);
    for (int i = 0; i < G[ind].size(); i++)
        if (!visited[G[ind][i].first])
            DFS(G[ind][i].first, len + G[ind][i].second, max_len);
    visited[ind] = false;
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;

    for (int i = 0; i < road.size(); i++)
    {
        G[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        G[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }

    DFS(1, 0, K);

    sort(node.begin(), node.end());
    node.erase(unique(node.begin(), node.end()), node.end());

    answer = node.size();

    return answer;
}