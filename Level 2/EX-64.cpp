#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    int ratio[] = { 2, 4, 3 };
    int div[] = { 1, 3, 2 };
    set<int> s;
    map<int, int> m;

    for (int weight : weights)
    {
        s.insert(weight);
        m[weight]++;
    }

    for (int w : s)
    {
        long long n = m[w];

        answer += n * (n - 1) / 2;

        for (int i = 0; i < 3; i++)
        {
            if (w % div[i] != 0)
                continue;

            int next = (w / div[i]) * ratio[i];
            long long t = m[next];

            answer += t * n;
        }
    }

    return answer;
}
