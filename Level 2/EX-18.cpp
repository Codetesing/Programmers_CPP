#include <string>
#include <vector>

using namespace std;

bool IS_RIGHT(string s)
{
    vector<char> stack;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            stack.push_back(s[i]);
        else
        {
            if (stack.empty())
                return false;
            else
            {
                if (stack[stack.size() - 1] == '(' && s[i] == ')')
                    stack.pop_back();
                else if (stack[stack.size() - 1] == '{' && s[i] == '}')
                    stack.pop_back();
                else if (stack[stack.size() - 1] == '[' && s[i] == ']')
                    stack.pop_back();
                else
                    return false;
            }
        }
    }

    if (!stack.empty())
        return false;
    else
        return true;
}

int solution(string s) {
    int answer = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (IS_RIGHT(s))
            answer++;
        char temp = s[0];
        s.erase(s.begin());
        s.push_back(temp);
    }

    return answer;
}