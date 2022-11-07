#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 51

int n;
string t;
vector<string> w;
vector<int> visited;
bool v[MAX] = {false};

bool CAN_CHANGE(string a, string b) {
    
    int cnt = 0;
    
    for(int i = 0; i < a.size(); i++)
    {   if(a[i] != b[i])
            cnt++;
        if(cnt == 2)
            return false;
    }
    
    return true;
}

void DFS(int ind, int cnt) {
    
    v[ind] = true;
    
    if(w[ind] == t) {
        visited[ind] = cnt;
        v[ind] = false;
        return;
    }
    
    for(int i = 0; i < n; i++)
        if(i != ind && CAN_CHANGE(w[i], w[ind]) && !v[i] && visited[i] > cnt)
            DFS(i, cnt + 1);
    v[ind] = false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    n = words.size();
    for(int i = 0; i < n; i++) visited.push_back(MAX);
    t = target;
    w = words;
    
    if(find(words.begin(), words.end(), target) == words.end())
        return answer;
    
    for(int i = 0; i < words.size(); i++)
        if(CAN_CHANGE(begin, words[i]))
            DFS(i, 1);
    
    answer = *min_element(visited.begin(), visited.end());
    
    return answer;
}
