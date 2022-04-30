#include <string>
#include <vector>

using namespace std;

bool deleted[30][30] = { false };
int row, col;
vector<string> board;

int FIND_DELETE_NUM()
{
    bool visited[30][30] = { false };
    int num = 0;

    for (int i = 0; i < row - 1; i++)
    {
        if (board[i].size() < 2 || board[i + 1].size() < 2)
            continue;

        for (int j = 0; j < board[i].size() - 1; j++)
        {
            char temp = board[i][j];

            if ((temp == board[i + 1][j]) && (temp == board[i][j + 1]) && (temp == board[i + 1][j + 1]))
            {
                visited[i][j] = true;
                visited[i + 1][j] = true;
                visited[i][j + 1] = true;
                visited[i + 1][j + 1] = true;
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        int ind = 0;
        for (int j = 0; j < board.size(); j++)
        {
            if (visited[i][j])
            {
                board[i].erase(board[i].begin() + j - ind);
                num++;
                ind++;
            }
        }
    }

    return num;
}

int solution(int m, int n, vector<string> s) {
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        string temp = "";
        for (int j = m - 1; j >= 0; j--)
            temp += s[j][i];
        board.push_back(temp);
    }
    row = n; col = m;
    while (1)
    {
        int deleted_num = FIND_DELETE_NUM();
        if (deleted_num == 0)
            break;
        else
            answer += deleted_num;
    }
    return answer;
}