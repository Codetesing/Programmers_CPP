#define MAX 1000000007

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> DP(n + 1, 0);

    DP[1] = 1;
    DP[2] = 2;

    for (int i = 3; i <= n; i++)
        DP[i] = (DP[i - 1] + DP[i - 2]) % MAX;

    answer = DP[n];

    return answer;
}