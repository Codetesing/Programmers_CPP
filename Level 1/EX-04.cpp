#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;

    string temp = "";
    string out = "";
    map<string, string> num;
    num["zero"] = "0";
    num["one"] = "1";
    num["two"] = "2";
    num["three"] = "3";
    num["four"] = "4";
    num["five"] = "5";
    num["six"] = "6";
    num["seven"] = "7";
    num["eight"] = "8";
    num["nine"] = "9";

    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]) == 0)
        {
            temp += s[i];
            if (num[temp] != "")
            {
                out += num[temp];
                temp = "";
            }
        }
        else
            out += s[i];
    }

    answer = stoi(out);

    return answer;
}