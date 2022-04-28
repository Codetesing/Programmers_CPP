#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

    int days;
    for (int i = 0; i < progresses.size(); i++)
    {
        days = 100 - progresses[i];
        if (days % speeds[i] == 0)
            days = days / speeds[i];
        else
            days = days / speeds[i] + 1;
        q.push(days);
    }

    while (!q.empty())
    {
        int cur = q.front();
        int num = 0;
        while (q.front() <= cur && !q.empty())
        {
            num++;
            q.pop();
        }

        answer.push_back(num);
    }

    return answer;
}