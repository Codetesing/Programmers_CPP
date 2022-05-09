#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    int cnt = 0;
    for (int i = 1; i < s.size() - 1; i++)
        if (s[i] == '{')
            cnt++;

    vector<vector<int>> set(cnt + 1);

    for (int i = 1; i < s.size() - 1; i++)
    {
        if (s[i] == '{')
        {
            i++;
            string num = "";
            vector<int> temp;
            while (i < s.size())
            {
                num += s[i];
                i++;
                if (s[i] == ',')
                {
                    temp.push_back(stoi(num));
                    num = "";
                    i++;
                }
                else if (s[i] == '}')
                {
                    temp.push_back(stoi(num));
                    break;
                }
            }
            
            set[temp.size()] = temp;
        }
    }

    for(int i = 1; i <= cnt; i++)
        for(int j = 0; j < set[i].size(); j++)
            if (find(answer.begin(), answer.end(), set[i][j]) == answer.end())
            {
                answer.push_back(set[i][j]);
                break;
            }

    return answer;
}