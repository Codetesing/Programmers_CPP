#include <string>
#include <vector>

using namespace std;

vector<int> ans(2, 0);
vector<vector<int>> map;

void QUARD(int start_x, int start_y, int n)
{
    int find_num = map[start_x][start_y];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if (map[start_x + i][start_y + j] != find_num)
            {
                n /= 2;
                QUARD(start_x, start_y, n);
                QUARD(start_x + n, start_y, n);
                QUARD(start_x, start_y + n, n);
                QUARD(start_x + n, start_y + n, n);
                return;
            }

    ans[find_num]++;
    return;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int n = arr.size();
    map = arr;

    QUARD(0, 0, n);

    answer = ans;

    return answer;
}