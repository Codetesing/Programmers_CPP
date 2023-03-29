#include <string>
#include <vector>

using namespace std;

vector<string> p;
int max_r, max_c;

vector<int> find_s() {
    for(int i = 0; i < p.size(); i++)
        for(int j = 0; j < p[i].size(); j++)
            if(p[i][j] == 'S')
                return {i, j};
}

bool execute_E(int r, int c, int len) {
    if(c + len >= max_c)
        return false;
    for(int i = 1; i <= len; i++)
        if(p[r][c + i] == 'X')
            return false;
    return true;
}

bool execute_W(int r, int c, int len) {
    if(c - len < 0)
        return false;
    for(int i = 1; i <= len; i++)
        if(p[r][c - i] == 'X')
            return false;
    return true;
}

bool execute_N(int r, int c, int len) {
    if(r - len < 0)
        return false;
    for(int i = 1; i <= len; i++)
        if(p[r - i][c] == 'X')
            return false;
    return true;
}

bool execute_S(int r, int c, int len) {
    if(r + len >= max_r)
        return false;
    for(int i = 1; i <= len; i++)
        if(p[r + i][c] == 'X')
            return false;
    return true;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    max_r = park.size();
    max_c = park[0].size();
    p = park;
    
    answer = find_s();
    
    for(int i = 0; i < routes.size(); i++) {
        char dir = routes[i][0];
        int len = routes[i][2] - '0';
        int r = answer[0];
        int c = answer[1];

        if(dir == 'E') {
            if(execute_E(r, c, len))
                answer[1] += len;
        }
        else if(dir == 'W') {
            if(execute_W(r, c, len))
                answer[1] -= len;
        }
        else if(dir == 'N') {
            if(execute_N(r, c, len))
                answer[0] -= len;
        }
        else if(dir == 'S') {
            if(execute_S(r, c, len))
                answer[0] += len;
        }
    }
    
    return answer;
}
