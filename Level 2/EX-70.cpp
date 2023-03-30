#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct COUNT {
    int d;
    int i;
    int s;
} COUNT;

int map[3][3] = { {1, 1, 1}, {5, 1, 1}, {25, 5, 1} };

bool compare(COUNT a, COUNT b) {
    if(a.d != b.d) return a.d > b.d;
    if(a.i != b.i) return a.i > b.i;
    return a.s > b.s;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    vector<COUNT> s;
    int m = (picks[0] + picks[1] + picks[2]) * 5;
    int n = minerals.size();
    
    int len = min(m, n);
    
    for(int i = 0; i < len; i += 5) {
        COUNT t = {0, 0, 0};
        for(int j = 0; j < 5; j++) {
            if(i + j >= len)
                break;
            if(minerals[i + j] == "diamond") t.d++;
            else if(minerals[i + j] == "iron") t.i++;
            else if(minerals[i + j] == "stone") t.s++;
        }
        
        s.push_back(t);
    }
    
    sort(s.begin(), s.end(), compare);
    
    int selected = 0;
    for(int i = 0; i < s.size(); i++) {
        if(selected == 3) break;
        
        if(picks[selected] == 0) {
            selected++;
            i--;
        }
        else {
            answer += map[selected][0] * s[i].d + map[selected][1] * s[i].i + map[selected][2] * s[i].s;
            picks[selected]--;
        }
    }
    
    return answer;
}
