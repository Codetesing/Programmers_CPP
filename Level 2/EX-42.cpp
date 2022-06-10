#include <string>
#include <vector>

using namespace std;

long long facto(long long num) {

    long long n = 1;

    for (int i = 2; i <= num; i++)
        n *= i;

    return n;
}

vector<int> solution(int n, long long k) {
    vector<int> answer, vt;
    for (int i = 1; i <= n; i++)
        vt.push_back(i);

    if (k == 1)
        return vt;

    k--;
    long long pre = facto(n);
    long long mod, div;

    while (vt.size() != 1) {
        pre /= n;
        mod = k % pre;
        div = k / pre;

        answer.push_back(vt[div]);
        vt.erase(vt.begin() + div);

        k = mod;
        n--;
    }
    answer.push_back(vt[0]);

    return answer;
}