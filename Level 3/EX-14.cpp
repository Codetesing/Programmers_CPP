#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 101

int p[MAX] = {0};

bool compare(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int find_p(int i) {
    if(p[i] == i)
        return i;
    
    return p[i] = find_p(p[i]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i = 1; i < n; i++)
        p[i] = i;
    
    sort(costs.begin(), costs.end(), compare);
    
    for(int i = 0; i < costs.size(); i++) {
        
        int pa = find_p(costs[i][0]);
        int pb = find_p(costs[i][1]);
        
        if(pa != pb) {
            if(pa > pb)
                p[pa] = pb;
            else
                p[pb] = pa;
            
            answer += costs[i][2];
        }
    }
    
    return answer;
}
