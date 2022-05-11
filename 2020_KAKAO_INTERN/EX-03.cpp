#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2, 0);
    map<string, int> gem;

    for (auto& i : gems)
        gem[i] = 0;

    int start = 0, end = 0;
    int gem_size = gem.size();
    int gem_cnt = 0;
    int min_len = 100001;
    while (1)
    {
        if (gem_cnt == gem_size)
        {
            if (end - start < min_len)
            {
                answer[0] = start + 1;
                answer[1] = end;
                min_len = end - start;
            }

            if (gem[gems[start]] <= 1)
                gem_cnt--;
            gem[gems[start]]--;
            start++;
        }
        else
        {
            if (end == gems.size())
                break;

            if (gem[gems[end]] == 0)
                gem_cnt++;
            gem[gems[end]]++;
            end++;
        }
    }

    return answer;
}
