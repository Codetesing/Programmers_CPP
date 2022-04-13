#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> part;
    
    for (int i = 0; i < completion.size(); i++)
        part[completion[i]] += 1;

    for (int i = 0; i < participant.size(); i++)
    {
        part[participant[i]] -= 1;
        if (part[participant[i]] < 0)
            return participant[i];
    }
}