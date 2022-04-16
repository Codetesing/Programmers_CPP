#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<float> failure(N, 0);

    sort(stages.begin(), stages.end());

    int total_num = stages.size();
    for (int i = 0; i < stages.size(); i++)
    {
        int cur = stages[i];

        if (cur == N + 1)
            break;

        int cnt = 1;

        for (; i != stages.size() - 1 && stages[i + 1] == cur; cnt++)
            i++;

        failure[cur - 1] = (float)cnt / total_num;
        total_num -= cnt;
    }

    for (int i = 1; i <= N; i++)
    {
        vector<float>::iterator it = max_element(failure.begin(), failure.end());
        *it = -1;
        answer.push_back(it - failure.begin() + 1);
    }

    return answer;
}
