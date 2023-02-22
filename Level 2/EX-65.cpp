#include <string>
#include <vector>
#include <queue>

using namespace std;

int r, c;
int rotate_x[] = {-1, 0, 0, 1};
int rotate_y[] = {0, 1, -1, 0};
vector<string> m;

pair<int, int> find_char(char a) {
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(m[i][j] == a)
                return {i, j};
}

int BFS(pair<int, int> s, pair<int, int> e) {
    queue<pair<int, int>> q;
    int visited[101][101] = {0};
    
    q.push(s);
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        
        if(cur == e) {
            return visited[cur.first][cur.second];
        }
        
        for(int i = 0; i < 4; i++) {
            int next_r = cur.first + rotate_x[i];
            int next_c = cur.second + rotate_y[i];
            
            if(next_r < 0 || next_r >= r || next_c < 0 || next_c >= c || m[next_r][next_c] == 'X')
                continue;
            
            if(next_r == s.first && next_c == s.second)
                continue;
            
            if(visited[next_r][next_c] == 0 || visited[next_r][next_c] > visited[cur.first][cur.second] + 1) {
                visited[next_r][next_c] = visited[cur.first][cur.second] + 1;
                q.push({next_r, next_c});
            }
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    r = maps.size();
    c = maps[0].size();
    m = maps;
    
    pair<int, int> start = find_char('S');
    pair<int, int> lever = find_char('L');
    pair<int, int> end = find_char('E');
    
    
    int temp = BFS(start, lever);
    int temp2 = BFS(lever, end);
    
    if(temp == -1 || temp2 == -1)
        return -1;
    else
        return temp + temp2;
}
