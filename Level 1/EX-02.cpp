#include <string>
#include <vector>

using namespace std;

int ranking(int n)
{
    switch (n) {
    case 6: return 1;
    case 5: return 2;
    case 4: return 3;
    case 3: return 4;
    case 2: return 5;
    default: return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int len = lottos.size();

    int zeros_num = 0;
    int cnt = 0;
    for (int i = 0; i < len; i++)
    {
        if (lottos[i] != 0)
        {
            for (int j = 0; j < len; j++)
                if (lottos[i] == win_nums[j])
                    cnt++;
        }
        else
            zeros_num++;
    }

    answer.push_back(ranking(cnt + zeros_num));
    answer.push_back(ranking(cnt));

    return answer;
}