#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;

    while (1)
    {
        if (a % 2 == 1)
            a++;
        if (b % 2 == 1)
            b++;

        if (a / 2 == b / 2)
            break;
        a /= 2;
        b /= 2;
        answer++;
    }

    return answer;
}