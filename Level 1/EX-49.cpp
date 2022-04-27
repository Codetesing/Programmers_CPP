using namespace std;

long long int COLLATZ(long long int n, int cnt)
{
    if (cnt == 501)
        return -1;

    if (n == 1)
        return cnt;

    if (n % 2 == 0)
        return COLLATZ(n / 2, cnt + 1);
    else
        return COLLATZ(n * 3 + 1, cnt + 1);
}

int solution(int num) {
    int answer = 0;

    answer = COLLATZ(num, 0);

    return answer;
}