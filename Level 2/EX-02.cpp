#include <iostream>

#include <string>
#include <vector>

using namespace std;

typedef struct user {
    string uid;
    string name;
}user;

vector<string> TRANS_RECORD(string s)
{
    vector<string> temp;

    int rev = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == ' ')
        {
            temp.push_back(s.substr(rev, rev - i));
            rev = i + 1;
        }

    return temp;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<user> enter;
    vector<user> leave;
    vector<user> change;
    vector<vector<string>> translated_record;

    for (int i = 0; i < record.size(); i++)
        translated_record.push_back(TRANS_RECORD(record[i]));

    for (int i = 0; i < translated_record.size(); i++)
    {
        for (int j = 0; j < translated_record[i].size(); j++)
            cout << translated_record[i][j] << ' ';
        cout << endl;
    }

    return answer;
}

int main()
{
    vector<string> temp = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
    solution(temp);
}