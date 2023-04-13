#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    int seq_sum[1001][1001] = {0};
    
    for(int i = 0; i < skill.size(); i++) {
        int degree = skill[i][5];
        if(skill[i][0] == 1)
            degree *= -1;
        
        seq_sum[skill[i][1]][skill[i][2]] += degree;
        seq_sum[skill[i][1]][skill[i][4] + 1] -= degree;
        seq_sum[skill[i][3] + 1][skill[i][2]] -= degree;
        seq_sum[skill[i][3] + 1][skill[i][4] + 1] += degree;
    }
    
    for(int i = 0; i < n + 1; i++)
        for(int j = 1; j < m + 1; j++)
            seq_sum[i][j] += seq_sum[i][j - 1];
    
    for(int i = 1; i < n + 1; i++)
        for(int j = 0; j < m + 1; j++)
            seq_sum[i][j] += seq_sum[i - 1][j];
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(board[i][j] + seq_sum[i][j] > 0)
                answer++;
    
    return answer;
}
