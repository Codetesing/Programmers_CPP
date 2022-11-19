#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 201
#define INF 2000000000

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    long long dis[MAX][MAX] = {};
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dis[i][j] = INF;
    
    for(int i = 0; i < fares.size(); i++) {
        dis[fares[i][0]][fares[i][1]] = fares[i][2];
        dis[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++){
                long long t = dis[j][i] + dis[i][k];
                if(dis[j][k] > t)
                    dis[j][k] = t;
            }
    
    answer = min(dis[s][a] + dis[a][b], dis[s][b] + dis[b][a]);
    if(dis[s][a] + dis[s][b] < answer)
        answer = dis[s][a] + dis[s][b];
    
    for(int i = 1; i <= n; i++){
        if(answer > dis[s][i] + dis[i][a] + dis[i][b])
            answer = dis[s][i] + dis[i][a] + dis[i][b];
    }
    
    return answer;
}
