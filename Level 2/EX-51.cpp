#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct NODE {
    int s;
    int e;
    int st;
    int et;
} NODE;

bool compare(NODE a, NODE b) {
    return a.s < b.s;
}

int solution(int distance, vector<vector<int>> scope, vector<vector<int>> times) {
    int answer = 0;
    
    vector<NODE> map;
    
    for(int i = 0; i < scope.size(); i++) {
        map.push_back({min(scope[i][0], scope[i][1]), max(scope[i][0],scope[i][1]), times[i][0], times[i][1]});
    }
    
    sort(map.begin(), map.end(), compare);
    
    int cur = 0;
    for(int i = 0; i < map.size(); i++) {
        int start = map[i].s;
        int end = map[i].e;
        int s_time = map[i].st;
        int e_time = map[i].et;
        int d = end - start;
        
        start = start % (s_time + e_time);
        
        if(start == 0)
        {
            answer = map[i].s + 1;
            break;
        }
        
        if(start <= s_time) {
            answer = map[i].s;
            break;
        }
        
        start -= s_time;
        if(e_time - start < d)
        {
            answer = map[i].s + e_time - start + 1;
            break;
        }
    }
    
    if(answer == 0)
        answer = distance;
    
    return answer;
}
