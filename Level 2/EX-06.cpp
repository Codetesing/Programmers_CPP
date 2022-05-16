#include <string>
#include <vector>
#include <queue>

using namespace std;

struct compare {
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, compare> queue;
    int first, second;

    for (int i = 0; i < scoville.size(); i++)
        queue.push(scoville[i]);

    while (queue.top() < K)
    {
        first = queue.top();
        queue.pop();

        if (queue.empty())
            break;

        second = queue.top();
        queue.pop();

        answer++;
        queue.push(first + second * 2);
    }

    if (queue.empty())
        answer = -1;

    return answer;
}