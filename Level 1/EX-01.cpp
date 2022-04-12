#include <string>
#include <vector>

using namespace std;

vector<string> split(string str)
{
    vector<string> out;

    string from = "";
    string to = "";

    int index = 0;
    int len = str.size();

    for(int i = 0; i < len; i++)
        if (str[i] == ' ')
        {
            index = i;
            break;
        }

    for (int i = 0; i < index; i++)
        from += str[i];
    for (int i = index + 1; i < len; i++)
        to += str[i];

    out.push_back(from);
    out.push_back(to);

    return out;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {

    int id_list_len = id_list.size();
    int report_len = report.size();
    bool visited[1000][1000] = { false };
    int reported[1000] = { 0 };
    vector<int> answer(id_list_len, 0);
    
    for (int i = 0; i < report_len; i++)
    {
        vector<string> temp = split(report[i]);

        int from = -1, to = -1;
        for (int i = 0; i < id_list_len; i++)
        {
            if (temp[0] == id_list[i])
                from = i;

            if (temp[1] == id_list[i])
                to = i;

            if (from != -1 && to != -1)
                break;
        }

        if (!visited[from][to])
        {
            visited[from][to] = true;
            reported[to]++;
        }
    }

    for (int i = 0; i < id_list_len; i++)
        if (reported[i] >= k)
            for (int j = 0; j < id_list_len; j++)
                if (visited[j][i])
                    answer[j]++;

    return answer;
}