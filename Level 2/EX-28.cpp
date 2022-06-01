#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> map(n, vector<int>(n, 0));

    int row = -1, col = 0, num = 1;

    for(int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            if (i % 3 == 0)
                row++;
            else if (i % 3 == 1)
                col++;
            else
            {
                row--;
                col--;
            }

            map[row][col] = num++;
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (map[i][j] != 0)
                answer.push_back(map[i][j]);

    return answer;
}