#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> graph(n + 1, vector<int>());
    vector<int> min_dist(n + 1, -1);
    queue<pair<int, int>> q;
    
    for(int i = 0; i < roads.size(); i++) {
        int start = roads[i][0];
        int end = roads[i][1];
        
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    
    q.push({destination, 0});
    min_dist[destination] = 0;
    while(!q.empty()) {
        int cur = q.front().first;
        int len = q.front().second;
        q.pop();
        
        for(int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            
            if(min_dist[next] == -1 || len + 1 < min_dist[next]) {
                q.push({next, len + 1});
                min_dist[next] = len + 1;
            }
        }
    }
    
    for(int i = 0; i < sources.size(); i++)
        answer.push_back(min_dist[sources[i]]);
    
    return answer;
}
