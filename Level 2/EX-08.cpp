#include<string>
#include<vector>

using namespace std;

int solution(string s)
{
    int answer = 0;
    vector<char> stack;

    for (int i = 0; i < s.size(); i++)
    {
        if (stack.empty())
            stack.push_back(s[i]);
        else
        {
            if (stack[stack.size() - 1] == s[i])
                stack.pop_back();
            else
                stack.push_back(s[i]);
        }
    }

    if (stack.empty())
        answer = 1;

    return answer;
}