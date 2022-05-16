#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
    return a.substr(6, 4) < b.substr(6, 4);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<string> car;
    vector<int> time;

    sort(records.begin(), records.end(), compare);

    int start, end;
    for (int i = 0; i < records.size(); i += 2)
    {
        start = stoi(records[i].substr(0, 2)) * 60 + stoi(records[i].substr(3, 2));

        if (i + 1 >= records.size() || records[i].substr(6, 4) != records[i + 1].substr(6, 4))
        {
            end = 23 * 60 + 59;
            i--;
        }
        else
            end = stoi(records[i + 1].substr(0, 2)) * 60 + stoi(records[i + 1].substr(3, 2));

        car.push_back(records[i + 1].substr(6, 4));
        time.push_back(end - start);
    }

    for (int i = 0; i < car.size() - 1; i++)
    {
        if (car[i] != car[i + 1])
            answer.push_back(time[i]);
        else
            time[i + 1] += time[i];
    }
    answer.push_back(time[time.size() - 1]);

    
    for (int i = 0; i < answer.size(); i++)
    {
        if (answer[i] <= fees[0])
            answer[i] = fees[1];
        else
        {
            if((answer[i] - fees[0]) % fees[2] == 0)
                answer[i] = fees[1] + (((answer[i] - fees[0]) / fees[2]) * fees[3]);
            else
                answer[i] = fees[1] + ((((answer[i] - fees[0]) / fees[2]) + 1) * fees[3]);
        }
    }

    return answer;
}