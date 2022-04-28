#include <string>
#include <vector>

using namespace std;

int CNT_LEN(int n)
{
    if (n == 1000)
        return 4;
    else if (n >= 100)
        return 3;
    else if (n >= 10)
        return 2;
    else if (n >= 2)
        return 1;
    else
        return 0;
}

int STRING_ZIP(int n, string s)
{
    vector<string> split;

    int ind = 0;
    int len = 0;
    
    for (int i = 0; i < s.size(); i += n)
        split.push_back(s.substr(i, n));

    int cnt = 1;
    while (split.size() !=  1)
    {
        if (split[0] == split[1])
            cnt++;
        else
        {
            len += n + CNT_LEN(cnt);
            cnt = 1;
        }
        split.erase(split.begin(), split.begin() + 1);
    }

    return len + CNT_LEN(cnt) + split[0].size();
}

int solution(string s) {
    int answer = s.size();

    for (int i = 1; i < s.size(); i++)
    {
        int temp = STRING_ZIP(i, s);

        if (answer > temp)
            answer = temp;
    }

    return answer;
}