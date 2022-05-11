#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

vector<long long> num;
vector<char> operand_pred;
map<int, char> temp;
bool visited[3] = { false };
string operand_list = "";
int cnt = 0;
long long ans = 0;

long long calculate(long long a, long long b, char op)
{
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
}

long long calculate_all()
{
    vector<long long> cal = num;
    string op_list = operand_list;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < op_list.size(); j++)
        {
            if (op_list[j] == operand_pred[i])
            {
                long long res = calculate(cal[j], cal[j + 1], op_list[j]);
                cal.erase(cal.begin() + j);
                cal[j] = res;
                op_list.erase(op_list.begin() + j);
                j--;
            }
        }
    }

    return abs(cal[0]);
}

void DFS(int ind)
{
    if (ind == 3)
    {
        long long res = calculate_all();
        ans = max(res, ans);
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            operand_pred.push_back(temp[i]);
            DFS(ind + 1);
            operand_pred.pop_back();
            visited[i] = false;
        }
    }
}

long long solution(string expression) {
    long long answer = 0;
    temp[0] = '+';
    temp[1] = '-';
    temp[2] = '*';

    string n = "";
    for (int i = 0; i < expression.size(); i++)
    {
        if (!isdigit(expression[i]))
        {
            num.push_back(stoll(n));
            n = "";
            operand_list += expression[i];
        }
        else
            n += expression[i];
    }
    num.push_back(stoll(n));

    DFS(0);

    answer = ans;
    return answer;
}