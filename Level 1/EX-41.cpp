#include <string>

using namespace std;

string solution(string s) {

    int cnt = 1;
    for (int i = 0, cnt = 1; i < s.size(); i++, cnt++)
    {
        if (s[i] != ' ')
        {
            if (cnt % 2 == 0)
                s[i] = tolower(s[i]);
            else
                s[i] = toupper(s[i]);
        }
        else
            cnt = 0;
    }

    return s;
}