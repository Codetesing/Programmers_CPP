#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<vector<int>> ans(3);
    ans[0] = { 1, 2, 3, 4, 5 };
    ans[1] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    ans[2] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    vector<int> cnt(3, 0);

    for (int i = 0; i < 3; i++)
    {
        int ind = 0;
        for (int j = 0; j < answers.size(); j++)
        {
            if (answers[j] == ans[i][ind])
                cnt[i]++;

            ind = (ind + 1) % ans[i].size();
        }
    }

    int max = *max_element(cnt.begin(), cnt.end());

    for (int i = 0; i < 3; i++)
        if (cnt[i] == max)
            answer.push_back(i + 1);

    return answer;
}