#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

int solution(int n) {
    int answer = 0;

    if (n % 2 == 1)
        return 0;

    vector<long long> DP(n + 1);
    DP[0] = 1;
    DP[2] = 3;

    for (int i = 4; i <= n; i += 2)
    {
        DP[i] = DP[i - 2] * 3;
        for (int j = i - 4; j >= 0; j -= 2)
            DP[i] += DP[j] * 2;
        DP[i] %= MOD;
    }

    answer = DP[n];

    return answer;
}