#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> hash;

    for (int i = 0; i < clothes.size(); i++)
        hash[clothes[i][1]]++;

    for (map<string, int>::iterator it = hash.begin(); it != hash.end(); it++)
        answer *= (it->second) + 1;

    return --answer;
}