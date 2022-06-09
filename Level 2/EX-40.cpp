#define DIV 1234567

#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<int> DP(n + 1, 0);
    DP[1] = 1;
    DP[2] = 2;

    for (int i = 3; i <= n; i++)
        DP[i] = (DP[i - 1] + DP[i - 2]) % DIV;

    answer = DP[n];

    return answer;
}