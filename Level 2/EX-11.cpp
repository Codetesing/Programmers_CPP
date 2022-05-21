#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> hash_table(21);

bool IS_HASH_TABLE(string str)
{
    for (int i = 1; i < str.size(); i++)
        for (int j = 0; j < hash_table[i].size(); j++)
            for (int k = 0; k < hash_table[i][j].size(); k++)
            {
                if (str[k] != hash_table[i][j][k])
                    break;
                else
                    if (k == hash_table[i][j].size() - 1)
                        return true;
            }

    return false;
}

bool solution(vector<string> phone_book) {

    sort(phone_book.begin(), phone_book.end());

    hash_table[phone_book[0].size()].push_back(phone_book[0]);

    for (int i = 1; i < phone_book.size(); i++)
    {
        if (IS_HASH_TABLE(phone_book[i]))
            return false;
        else
            hash_table[phone_book[i].size()].push_back(phone_book[i]);
    }
    return true;
}