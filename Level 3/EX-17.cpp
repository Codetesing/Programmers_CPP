#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10001

vector<vector<string>> t;
bool visited[MAX] = {false};
int n;

bool compare(vector<string> a, vector<string> b) {
    if(a[0] == b[0])
        return a[1] < b[1];
    else
        return a[0] < b[0];
}

bool DFS(string start, vector<string>& ans, int cur) {

    ans.push_back(start);
    
    if(ans.size() == n + 1)
        return true;
    
    for(int i = 0; i < n; i++) {
        if(t[i][0] == start && !visited[i]) {
            visited[i] = true;
            if(DFS(t[i][1], ans, i)) return true;
            visited[i] = false;
        }
    }
    
    ans.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    n = tickets.size();
    
    sort(tickets.begin(), tickets.end());
    t = tickets;
    
    DFS("ICN", answer, -1);
    
    return answer;
}
