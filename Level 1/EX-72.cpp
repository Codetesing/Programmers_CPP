#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int alpha[26] = {0};

int find_min_cnt(string s) {
    int cnt = 0;
    
    for(int i = 0; i < s.size(); i++) {
        if(alpha[s[i] - 'A'] == 0)
            return -1;
        cnt += alpha[s[i] - 'A'];
    }
    
    return cnt;
}

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for(int i = 0; i < keymap.size(); i++) {
        for(int j = 0; j < keymap[i].size(); j++) {
            int ind = keymap[i][j] - 'A';
            
            if(alpha[ind] == 0)
                alpha[ind] = j + 1;
            else
                alpha[ind] = min(alpha[ind], j + 1);
        }
    }
    
    for(int i = 0; i < targets.size(); i++)
        answer.push_back(find_min_cnt(targets[i]));
    
    return answer;
}
