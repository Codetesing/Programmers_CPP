#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    map<string, int> reported_num;
    vector<string> from;
    vector<string> to;

    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());

    for (int i = 0; i < report.size(); i++)
    {
        for (int j = 0; j < report[i].size(); j++)
        {
            if (report[i][j] == ' ')
            {
                from.push_back(report[i].substr(0, j));
                to.push_back(report[i].substr(j + 1, report[i].size()));
                break;
            }
        }
    }
    
    for (int i = 0; i < to.size(); i++)
        reported_num[to[i]]++;

    for (int i = 0; i < from.size(); i++)
    {
        int ind = find(id_list.begin(), id_list.end(), from[i]) - id_list.begin();
        if (reported_num[to[i]] >= k)
            answer[ind]++;
    }

    return answer;
}

