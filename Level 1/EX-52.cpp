#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    int len = phone_number.size();
    string answer = phone_number.substr(len - 4, len);

    for (int i = 0; i < len - 4; i++)
        answer = "*" + answer;

    return answer;
}