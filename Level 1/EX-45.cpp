#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = -1;

    if (sqrtl(n) == floorl(sqrtl(n)))
        answer = pow(sqrtl(n) + 1, 2);

    return answer;
}