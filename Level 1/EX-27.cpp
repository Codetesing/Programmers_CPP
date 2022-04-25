#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;

    int prev = 0;
    for (int i = 0; i < dartResult.size(); i += 2)
    {
        int score = dartResult[i] - '0';
        
        if (dartResult[i + 1] == '0')
        {
            score = 10;
            i++;
        }
        if (dartResult[i + 1] == 'D')
            score *= score;
        if (dartResult[i + 1] == 'T')
            score *= score * score;

        if (dartResult[i + 2] == '#')
        {
            score *= -1;
            i++;
        }
        else if (dartResult[i + 2] == '*')
        {
            score *= 2;
            answer += prev;
            i++;
        }

        answer += score;
        prev = score;
    }
    return answer;
}