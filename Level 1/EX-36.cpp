#include <string>
#include <vector>

using namespace std;

bool IS_PRIME(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int solution(int n) {
    int answer = 0;

    for (int i = 2; i <= n; i++)
        if (IS_PRIME(i))
            answer++;

    return answer;
}