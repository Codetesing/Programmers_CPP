#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;

    for (int i = 0, temp = x; i < n; i++, temp += x)
        answer.push_back(temp);

    return answer;
}