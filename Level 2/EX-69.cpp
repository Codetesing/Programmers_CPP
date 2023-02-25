#include <string>
#include <vector>

using namespace std;

int n = 3;

bool WIN(vector<string> g, char win) {
    bool flag;
    
    for(int i = 0; i < n; i++) {
        flag = true;
        for(int j = 0; j < n; j++) {
            if(g[i][j] != win) {
                flag = false;
                break;
            }
        }
        if(flag)
            return true;
    }
    for(int i = 0; i < n; i++) {
        flag = true;
        for(int j = 0; j < n; j++) {
            if(g[j][i] != win) {
                flag = false;
                break;
            }
        }
        if(flag)
            return true;
    }
    
    flag = true;
    for(int i = 0; i < n; i++)
        if(g[i][i] != win) {
            flag = false;
            break;
        }
    if(flag)
            return true;
    
    flag = true;
    for(int i = 0; i < n; i++)
        if(g[i][n - i - 1] != win) {
            flag = false;
            break;
        }
    if(flag)
            return true;
    
    return false;
}

int solution(vector<string> board) {
    int answer = -1;
    int cnt_o = 0, cnt_x = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 'O')
                cnt_o++;
            else if(board[i][j] == 'X')
                cnt_x++;
        }
    }
    
    if(cnt_o < cnt_x)
        return 0;
    else if(cnt_o == cnt_x) {
        if(WIN(board, 'O'))
            return 0;
        else 
            return 1;
    }
    else {
        if(WIN(board, 'X'))
            return 0;
        else {
            if(cnt_o - cnt_x > 1)
                return 0;
            else
                return 1;
        }
    }
}
