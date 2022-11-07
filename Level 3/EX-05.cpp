#include <string>
#include <vector>

using namespace std;

#define MAX 201

vector<vector<int>> graph;
bool visited[MAX] = {false};

void DFS(int n) {

    visited[n] = true;
    
    for(int i = 0; i < graph[n].size(); i++) {
        if(!visited[graph[n][i]])
            DFS(graph[n][i]);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++) {
        graph.push_back(vector<int>());
        for(int j = 0; j < n; j++)
            if(i != j && computers[i][j] == 1)
                graph[i].push_back(j);
    }
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            answer++;
            DFS(i);
        }
    }
    
    return answer;
}
