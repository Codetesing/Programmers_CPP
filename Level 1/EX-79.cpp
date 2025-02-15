#include <string>
#include <vector>

using namespace std;

int rx[] = {-1, 0, 0, 1};
int ry[] = {0, -1, 1, 0};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int n = board.size();
    
    for(int i = 0; i < 4; i++) {
        int nx = h + rx[i];
        int ny = w + ry[i];
        
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
            continue;
        }
        
        if(board[nx][ny] == board[h][w]) {
            answer++;
        }
    }
    
    return answer;
}
