#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

#define MAX 101

using namespace std;

bool visited[MAX] = {false};
vector<vector<int>> map;
vector<int> c;
int ind = 0;

void DFS(int n) {
    
    if(visited[n])
        return;
    
    map[ind].push_back(n);
    visited[n] = true;
    
    int next = c[n] - 1;
    
    DFS(next);
}

int solution(vector<int> cards) {
    int answer = 0;
    c = cards;
    
    for(int i = 0; i < cards.size(); i++) {
        if(!visited[i]) {
            map.push_back(vector<int>());
            DFS(i);
            ind++;
        }
    }
    
    vector<int> cnt;
    for(int i = 0; i < ind; i++)
        cnt.push_back(map[i].size());
    
    vector<int>::iterator it = max_element(cnt.begin(), cnt.end());
    
    int a = *it;
    cnt[it - cnt.begin()] = 0;
    
    int b = *max_element(cnt.begin(), cnt.end());
    
    answer = a * b;
    
    return answer;
}
