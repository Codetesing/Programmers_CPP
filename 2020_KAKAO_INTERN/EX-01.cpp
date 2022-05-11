#include <string>
#include <vector>
#include <cmath>

using namespace std;

int nums[4][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1} };

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int left_row = 3, left_col = 0;
    int right_row = 3, right_col = 2;

    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            left_row = numbers[i] / 3;
            left_col = 0;
            answer += "L";
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            right_row = (numbers[i] / 3) - 1;
            right_col = 2;
            answer += "R";
        }
        else
            for (int m = 0; m < 4; m++)
                if (nums[m][1] == numbers[i])
                {
                    int left = abs(left_row - m) + abs(left_col - 1);
                    int right = abs(right_row - m) + abs(right_col - 1);

                    if (left > right)
                    {
                        right_row = m;
                        right_col = 1;
                        answer += "R";
                    }
                    else if (left < right)
                    {
                        left_row = m;
                        left_col = 1;
                        answer += "L";
                    }
                    else
                    {
                        if (hand == "right")
                        {
                            right_row = m;
                            right_col = 1;
                            answer += "R";
                        }
                        else
                        {
                            left_row = m;
                            left_col = 1;
                            answer += "L";
                        }
                    }
                    break;
                }
    }

    return answer;
}