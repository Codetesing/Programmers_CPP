#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> user;
vector<string> ban;
vector<vector<string>> banned_list;
vector<string> temp;
int user_size, ban_size;
int ans = 0;
bool visited[8] = { false };

bool CAN_BAN(string a, string b)
{
    if (a.size() != b.size())
        return false;

    for (int i = 0; i < a.size(); i++)
        if (b[i] != '*' && a[i] != b[i])
            return false;

    return true;
}

bool IS_SAME()
{
    if (banned_list.size() == 0)
        return true;

    for (int i = 0; i < banned_list.size(); i++)
        for (int j = 0; j < temp.size(); j++)
        {
            if (find(banned_list[i].begin(), banned_list[i].end(), temp[j]) == banned_list[i].end())
                break;

            if (j == temp.size() - 1)
                return false;
        }
    return true;
}

void DFS(int user_ind, int banned_ind)
{
    if (banned_ind == ban_size - 1)
    {
        temp.push_back(user[user_ind]);
        
        if (IS_SAME())
            banned_list.push_back(temp);

        temp.pop_back();
        return;
    }

    visited[user_ind] = true;
    temp.push_back(user[user_ind]);
    banned_ind++;

    for (int i = 0; i < user_size; i++)
        if (i != user_ind && !visited[i])
            if (CAN_BAN(user[i], ban[banned_ind]))
                DFS(i, banned_ind);

    visited[user_ind] = false;
    temp.pop_back();
}

int solution(vector<string> user_id, vector<string> banned_id) {

    int answer = 0;
    user = user_id;
    ban = banned_id;
    user_size = user_id.size();
    ban_size = banned_id.size();

    for (int i = 0; i < user_size; i++)
        if (CAN_BAN(user_id[i], banned_id[0]))
            DFS(i, 0);

    answer = banned_list.size();

    return answer;
}

int main()
{
    vector<string> a = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
    vector<string> b = { "fr*d*", "*rodo", "******", "******" };

    solution(a, b);
}