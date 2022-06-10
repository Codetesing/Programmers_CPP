#include <string>
#include <vector>

using namespace std;

int check(int n) {

    if (n == 1)
        return 0;

    for (int i = 2; i * i <= n; i++)
        if (n % i == 0 && n / i <= 10000000)
            return n / i;

    return 1;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;

    for (int i = begin; i <= end; i++)
        answer.push_back(check(i));

    if (begin == 1) answer[0] = 0;
    return answer;
}