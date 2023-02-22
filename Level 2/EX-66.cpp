#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> g;
bool visited[101][101];
int area_count, row_n, col_n;
int rotate_x[] = {-1, 0, 0, 1};
int rotate_y[] = {0, -1, 1, 0};

void DFS(int row, int col, int value) {
    area_count++;
    visited[row][col] = true;
    
    for(int i = 0; i < 4; i++) {
        int next_row = row + rotate_x[i];
        int next_col = col + rotate_y[i];
        
        if(next_row < 0 || next_row >= row_n || next_col < 0 || next_col >= col_n)
            continue;
        if(!visited[next_row][next_col] && value == g[next_row][next_col])
            DFS(next_row, next_col, value);
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    g = picture;
    row_n = m; col_n = n;
    
    for(int i = 0; i < 101; i++)
        for(int j = 0; j < 101; j++)
            visited[i][j] = false;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(picture[i][j] != 0 && !visited[i][j]) {
                area_count = 0;
                DFS(i, j, picture[i][j]);
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, area_count);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
