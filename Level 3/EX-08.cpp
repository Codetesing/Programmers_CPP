#include <vector>
#include <string>

#define MOD 1000000007

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    vector<vector<int>> DP(m + 1,vector<int>(n + 1, 0));
    for(int i = 0; i < puddles.size(); i++) DP[puddles[i][0]][puddles[i][1]] = -1;
    
    DP[1][1]=1;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(DP[i][j] == -1) 
                DP[i][j]= 0;
            else 
                DP[i][j] += (DP[i - 1][j] + DP[i][j - 1]) % MOD;
        }
    }

    return answer = DP[m][n];
}
