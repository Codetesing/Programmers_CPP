#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long FIND_EMPTY_NUM(vector<long long> num, long long n)
{
    while (1)
    {
        n++;
        if (find(num.begin(), num.end(), n) == num.end())
            return n;
    }
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    vector<long long> parent(room_number.size(), 0);

    for (int i = 0; i < room_number.size(); i++)
    {
        vector<long long>::iterator it = find(answer.begin(), answer.end(), room_number[i]);
        if (it == answer.end())
            answer.push_back(room_number[i]);

        else
            answer.push_back(FIND_EMPTY_NUM(answer, room_number[i]));
    }

    return answer;
}