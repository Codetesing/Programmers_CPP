#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> map(101, vector<int>(101, 0));

int ROTATE_MAP(vector<int> pos)
{
    int Min_Num;
    int Temp = map[pos[0]][pos[1]];
    Min_Num = Temp;
    for (int i = pos[0]; i < pos[2]; i++)
    {
        Min_Num = min(Min_Num, map[i][pos[1]]);
        map[i][pos[1]] = map[i + 1][pos[1]];
    }
    for (int i = pos[1]; i < pos[3]; i++)
    {
        Min_Num = min(Min_Num, map[pos[2]][i]);
        map[pos[2]][i] = map[pos[2]][i + 1];
    }
    for (int i = pos[2]; i > pos[0]; i--)
    {
        Min_Num = min(Min_Num, map[i][pos[3]]);
        map[i][pos[3]] = map[i - 1][pos[3]];
    }
    for (int i = pos[3]; i > pos[1]; i--)
    {
        Min_Num = min(Min_Num, map[pos[0]][i]);
        map[pos[0]][i] = map[pos[0]][i - 1];
    }
    map[pos[0]][pos[1] + 1] = Temp;
    return Min_Num;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int num = 1;

    for (int i = 1; i <= rows; i++)
        for (int j = 1; j <= columns; j++)
            map[i][j] = num++;

    for (int i = 0; i < queries.size(); i++)
        answer.push_back(ROTATE_MAP(queries[i]));

    return answer;
}