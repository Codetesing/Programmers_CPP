#include <string>
#include <vector>

using namespace std;

bool IS_FINE(char a)
{
    if (a >= 'a' && a <= 'z')
        return true;
    if (a >= '0' && a <= '9')
        return true;
    if (a == '-' || a == '_' || a == '.')
        return true;

    return false;
}

string solution(string new_id) {
    string answer = "";

    for (int i = 0; i < new_id.length(); i++)
        if (new_id[i] >= 'A' && new_id[i] <= 'Z')
            new_id[i] += 32;

    for (int i = 0; i < new_id.length();)
    {
        if (!IS_FINE(new_id[i]))
            new_id.erase(new_id.begin() + i);
        else
            i++;
    }

    for (int i = 0; i < new_id.length() - 1; )
    {
        if (new_id[i] == '.' && new_id[i + 1] == '.')
            new_id.erase(new_id.begin() + i);

        else i++;
    }

    if (new_id[0] == '.')
        new_id.erase(new_id.begin());

    if (new_id[new_id.length() - 1] == '.')
        new_id.erase(new_id.begin() + new_id.length() - 1);

    if (new_id.empty())
        new_id = "a";

    if (new_id.size() > 15)
        new_id.resize(15);

    if (new_id[new_id.length() - 1] == '.')
        new_id.erase(new_id.begin() + new_id.length() - 1);

    while (new_id.size() < 3)
        new_id.push_back(new_id.back());

    answer = new_id;

    return answer;
}