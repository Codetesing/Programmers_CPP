#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(int a, int b, int n) {
    queue<int> q;
    int visited[1000001] = {0};
    
    q.push(a);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if(cur == b)
            return visited[cur];
        
        int next_1 = cur * 2;
        int next_2 = cur * 3;
        int next_3 = cur + n;
        
        if(!visited[next_1] && next_1 <= b) {
            q.push(next_1);
            visited[next_1] = visited[cur] + 1;
        }
        if(!visited[next_2] && next_2 <= b) {
            q.push(next_2);
            visited[next_2] = visited[cur] + 1;
        }
        if(!visited[next_3] && next_3 <= b) {
            q.push(next_3);
            visited[next_3] = visited[cur] + 1;
        }
    }
    
    return -1;
}

int solution(int x, int y, int n) {
    int answer = 0;
    
    answer = bfs(x, y, n);
    
    return answer;
}
