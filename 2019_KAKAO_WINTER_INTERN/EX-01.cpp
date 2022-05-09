#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> temp;
    for (int i = 0; i < moves.size(); i++)
    {
        int ind = moves[i] - 1;
        for(int j = 0; j < board.size(); j++)
            if (board[j][ind])
            {
                if (temp.empty())
                    temp.push_back(board[j][ind]);
                else
                {
                    if (temp[temp.size() - 1] == board[j][ind])
                    {
                        answer += 2;
                        temp.pop_back();
                    }
                    else
                        temp.push_back(board[j][ind]);
                }
                board[j][ind] = 0;
                break;
            }
    }

    return answer;
}