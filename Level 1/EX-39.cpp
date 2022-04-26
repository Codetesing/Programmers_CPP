#include <string>

using namespace std;

string solution(string s, int n) {
    string answer = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            answer += s[i];
        else if (islower(s[i]))
            answer += (s[i] - 'a' + n) % 26 + 'a';
        else if (isupper(s[i]))
            answer += (s[i] - 'A' + n) % 26 + 'A';
    }
    return answer;
}