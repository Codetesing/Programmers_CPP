#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int out = 9, n, num;

void DFS(int cnt, int cur)
{
    if (cnt > 8)
        return;

    if (cur == num)
    {
        out = min(cnt, out);
        return;
    }

    int temp = 0;
    for (int i = 0; i + cnt < 9; i++)
    {
        temp = temp * 10 + n;
        DFS(cnt + 1 + i, cur + temp);
        DFS(cnt + 1 + i, cur - temp);
        DFS(cnt + 1 + i, cur * temp);
        DFS(cnt + 1 + i, cur / temp);
    }
}

int solution(int N, int number) {
    int answer = 0;
    n = N; num = number;

    DFS(0, 0);

    answer = out;

    if (answer > 8)
        answer = -1;

    return answer;
}