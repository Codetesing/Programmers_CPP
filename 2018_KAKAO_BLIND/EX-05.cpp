#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> time;

    for (int i = 0; i < timetable.size(); i++)
    {
        string H = timetable[i].substr(0, 2);
        string M = timetable[i].substr(3, 2);

        time.push_back(stoi(H) * 60 + stoi(M));
    }

    sort(time.begin(), time.end());

    int last = 9 * 60 + t * (n - 1);
    int limit_num = m * n;

    int cnt = 0;
    int flag = 0;
    int temp;
    
    int start = 9 * 60;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (time.empty())
                break;

            if (time[0] <= start)
                time.erase(time.begin());
            else
                break;
        }
        start += t;
    }

    for (int j = 0; j < m - 1; j++)
    {
        if (time.empty())
            break;

        if (time[0] <= start)
            time.erase(time.begin());
        else
            break;
    }

    if (time.empty())
        temp = last;
    else
    {
        if (time[0] <= last)
            temp = time[0] - 1;
        else
            temp = last;
    }

    int H = temp / 60;
    int M = temp % 60;

    if (H < 10)
        answer += "0";
    answer += to_string(H);
    answer += ":";
    if (M < 10)
        answer += "0";
    answer += to_string(M);

    return answer;
}