#include <iostream>

#include <string>
#include <vector>

using namespace std;

#define MAX 1000001

bool visited[MAX] = {false};

int solution(vector<int> elements) {
    int answer = 0;
    
    int n = elements.size();
    vector<vector<int>> DP(n + 1, vector<int>(n + 1, 0));
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int ind = (i + j) % n;
            DP[i][j] = DP[i - 1][j] + elements[ind];
            visited[DP[i][j]] = true;
        }
    }

    for(int i = 0; i < MAX; i++)
        if(visited[i])
        {
            answer++;
        }
        
    return answer;
}