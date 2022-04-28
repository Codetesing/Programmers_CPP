#include <algorithm>

using namespace std;

long long GCD(long long a, long long b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

long long solution(int w, int h) {
    long long W = w;
    long long H = h;
    long long answer = W * H;
    long long gcd = GCD(W, H);

    answer = answer - (W + H - gcd);
    
    return answer;
}