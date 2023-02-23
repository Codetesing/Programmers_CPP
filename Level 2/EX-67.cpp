#include <string>
#include <vector>

using namespace std;

int discount[] = {10, 20, 30, 40};
int visited[10] = {0};
int n, m;
int max_cnt = 0, max_value = 0;
vector<int> emo;
vector<vector<int>> user;

pair<int, int> buy_emoticon() {
    int user_cnt = 0;
    int user_value = 0;
    
    for(int i = 0; i < n; i++) {
        int temp_value = 0;
        
        for(int j = 0; j < m; j++) {
            if(visited[j] >= user[i][0])
                temp_value += emo[j];
        }
        
        if(temp_value >= user[i][1])
            user_cnt++;
        else
            user_value += temp_value;
    }
    
    return {user_cnt, user_value};
}

void DFS(int cnt) {
    if(cnt == m) {
        pair<int,int> p = buy_emoticon();
        
        if(p.first > max_cnt) {
            max_cnt = p.first;
            max_value = p.second;
        }
        else if(p.first == max_cnt && p.second > max_value) {
            max_value = p.second;
        }
            
        return;
    }
    
    int temp = emo[cnt];
    for(int i = 0; i < 4; i++) {
        emo[cnt] = temp - temp / 100 * discount[i];
        visited[cnt] = discount[i];
        DFS(cnt + 1);
    }
    emo[cnt] = temp;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    emo = emoticons;
    user = users;
    n = users.size();
    m = emoticons.size();
    
    DFS(0);
    
    answer.push_back(max_cnt);
    answer.push_back(max_value);
    
    return answer;
}
