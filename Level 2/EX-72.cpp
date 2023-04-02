#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct pos {
    int x;
    int y;
    int cnt;
} pos;

int N, M;
vector<string> b;

pos FIND_START() {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(b[i][j] == 'R') {
                return {i, j, 0};
            }
}

pos FIND_NEXT(pos p, int dir) {
    pos n = p;
    n.cnt++;
    
    if(dir == 0) {
        while(n.x - 1 != -1 && b[n.x - 1][n.y] != 'D')
            n.x--;
    }
    else if(dir == 1) {
        while(n.x + 1 != N && b[n.x + 1][n.y] != 'D')
            n.x++;
    }
    else if(dir == 2) {
        while(n.y - 1 != -1 && b[n.x][n.y - 1] != 'D')
            n.y--;
    }
    else if(dir == 3) {
        while(n.y + 1 != M && b[n.x][n.y + 1] != 'D')
            n.y++;
    }
    
    return n;
}

int BFS() {
    queue<pos> q;
    bool visited[101][101] = {false};
    pos start = FIND_START();
    q.push(start);
    
    while(!q.empty()) {
        pos cur = q.front();
        q.pop();
        
        if(visited[cur.x][cur.y]) continue;
        
        if(b[cur.x][cur.y] == 'G') return cur.cnt;
        
        visited[cur.x][cur.y] = true;
        for(int i = 0; i < 4; i++) {
            pos next = FIND_NEXT(cur, i);
            
            if(!visited[next.x][next.y]) q.push(next);
        }
    }
    
    return -1;
}

int solution(vector<string> board) {
    int answer = 0;
    N = board.size();
    M = board[0].size();
    b = board;
    
    answer = BFS();
    
    return answer;
}
