#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

vector<string> TRANS_RECORD(string s)
{
    vector<string> temp;

    int rev = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == ' ')
        {
            temp.push_back(s.substr(rev, i));
            rev = i + 1;
            break;
        }

    if (temp[0] == "Leave")
        temp.push_back(s.substr(rev));
    else
        for(int i = 0; i < s.size() - rev; i++)
            if (s[rev + i] == ' ')
            {
                temp.push_back(s.substr(rev, i));
                temp.push_back(s.substr(rev + i + 1, s.size() - rev - i - 1));
                break;
            }

    return temp;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> translated_record;
    map<string, string> user;

    for (int i = 0; i < record.size(); i++)
        translated_record.push_back(TRANS_RECORD(record[i]));

    for (int i = 0; i < translated_record.size(); i++)
    {
        if (translated_record[i][0] != "Leave")
        {
            if (user.find(translated_record[i][1]) == user.end())
                user.insert(pair<string, string>(translated_record[i][1], translated_record[i][2]));
            else
                user[translated_record[i][1]] = translated_record[i][2];
        }
    }

    for (int i = 0; i < translated_record.size(); i++)
    {
        if (translated_record[i][0] == "Enter")
            answer.push_back(user[translated_record[i][1]] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
        else if(translated_record[i][0] == "Leave")
            answer.push_back(user[translated_record[i][1]] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
    }
    return answer;
}

int main()
{
    vector<string> temp = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
    solution(temp);
}