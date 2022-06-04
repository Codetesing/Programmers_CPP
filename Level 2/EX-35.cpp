#include <iostream>

#include <string>
#include <vector>

using namespace std;

string TO_BINARY(int n)
{
    string re = "";

    for (; n != 0; n /= 2)
    {
        if (n % 2 == 0)
            re = '0' + re;
        else
            re = '1' + re;
    }

    return re;
}

vector<int> solution(string s) {
    vector<int> answer(2, 0);

    while (1)
    {
        int cnt = 0;
        if (s == "1")
            break;

        for (int i = 0; i < s.size(); i++)
            if(s[i] == '1')
                cnt++;

        answer[0]++;
        answer[1] += s.size() - cnt;

        s = TO_BINARY(cnt);
    }

    return answer;
}