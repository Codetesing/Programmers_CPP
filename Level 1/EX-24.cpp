using namespace std;

long long solution(int price, int money, int count)
{
    long long ans = money;

    for (int i = 1; i <= count; i++)
        ans -= i * price;

    if (ans > 0)
        ans = 0;
    else
        ans *= -1;

    return ans;
}