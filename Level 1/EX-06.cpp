#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> bucket;
    int N = board.size();

    for(int i = 0; i < moves.size(); i++)
        for(int j = 0; j < N; j++)
            if (board[j][moves[i] - 1] != 0)
            {
                int doll = board[j][moves[i] - 1];
                board[j][moves[i] - 1] = 0;

                if (!bucket.empty())
                {
                    if (bucket.back() == doll)
                    {
                        bucket.pop_back();
                        answer += 2;
                    }
                    else
                        bucket.push_back(doll);
                }
                else
                    bucket.push_back(doll);
                break;
            }

    return answer;
}