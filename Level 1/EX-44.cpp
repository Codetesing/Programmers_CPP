#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> arr;

    for (int i = 10; n != 0; n /= 10)
        arr.push_back(n % 10);

    sort(arr.begin(), arr.end());

    long long mul = 1;
    for (int i = 0; i < arr.size(); i++, mul *= 10)
        answer += mul * arr[i];

    return answer;
}