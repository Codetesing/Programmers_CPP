#include <algorithm>
#include <vector>

using namespace std;

int GCD(int a, int b)
{

    if (b == 0)
        return a;

    else
        return GCD(b, a % b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;

    int gcd = GCD(n, m);
    int lcm = n * m / gcd;

    answer.push_back(gcd);
    answer.push_back(lcm);

    return answer;
}
