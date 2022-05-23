#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> prime;
string n;
bool visited[10] = { false };

bool IS_PRIME(int n)
{
    if (n < 2)
        return false;

    if (n == 2 || n == 3)
        return true;

    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}

void DFS(int ind, int cnt, string cur)
{
    visited[ind] = true;

    if (IS_PRIME(stoi(cur)))
        prime.push_back(stoi(cur));

    for (int i = 0; i < n.size(); i++)
        if (!visited[i])
            DFS(i, cnt + 1, cur + n[i]);
    visited[ind] = false;
}

int solution(string numbers) {
    int answer = 0;
    n = numbers;

    for (int i = 0; i < numbers.size(); i++)
        DFS(i, 1, to_string(numbers[i] - '0'));

    sort(prime.begin(), prime.end());
    prime.erase(unique(prime.begin(), prime.end()), prime.end());

    answer = prime.size();

    return answer;
}