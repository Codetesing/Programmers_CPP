#include <string>

using namespace std;

bool solution(string s)
{
    int p_num = 0, y_num = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'P' || s[i] == 'p') 
            p_num++;
        else if (s[i] == 'Y' || s[i] == 'y') 
            y_num++;
    }

    return p_num == y_num;
}