#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;

typedef struct cond {
    char f;
    char t;
    char d;
    int len;
} cond;

vector<cond> conds;
bool visited[8] = {false};
char index[] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
int result = 0;
map<char, int> m;

bool check() {
    for(int i = 0; i < conds.size(); i++) {
        cond c = conds[i];
        int cond_len = abs(m[c.f] - m[c.t]) - 1;
        
        if(c.d == '=' && cond_len != c.len)
            return false;
        if(c.d == '<' && cond_len >= c.len)
            return false;
        if(c.d == '>' && cond_len <= c.len)
            return false;
    }
    return true;
}

void DFS(int ind) {
    if(ind == 8) {
        if(check())
            result++;
        return;
    }
    
    for(int i = 0; i < 8; i++) {
        if(visited[i]) continue;
        
        m[index[i]] = ind;
        visited[i] = true;
        DFS(ind + 1);
        visited[i] = false;
    }
}

int solution(int n, vector<string> data) {
    int answer = 0;
    conds.clear();
    m.clear();
    result = 0;
    
    for(int i = 0; i < n; i++)
        conds.push_back({data[i][0], data[i][2], data[i][3], (data[i][4] - '0')});
    
    DFS(0);
    
    answer = result;
    
    return answer;
}
