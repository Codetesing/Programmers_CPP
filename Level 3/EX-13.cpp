#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 20001

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> G(n + 1, vector<int>());
    queue<int> q;
    vector<int> D(n + 1, -1);
    
    for(int i = 0; i < edge.size(); i++) {
        G[edge[i][0]].push_back(edge[i][1]);
        G[edge[i][1]].push_back(edge[i][0]);
    }
    
    q.push(1);
    D[1] = 0;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int i = 0; i < G[cur].size(); i++)
            if(D[G[cur][i]] == -1) {
                D[G[cur][i]] = D[cur] + 1;
                q.push(G[cur][i]);
            }
    }
    
    int max_val = *max_element(D.begin(), D.end());
    
    for(int i = 1; i <= n; i++)
        if(D[i] == max_val)
            answer++;
    
    return answer;
}
