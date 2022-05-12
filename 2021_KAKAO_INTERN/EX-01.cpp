#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    string num = "";
    string temp = "";
    map<string, string> m;
    m["zero"] = "0";
    m["one"] = "1";
    m["two"] = "2";
    m["three"] = "3";
    m["four"] = "4";
    m["five"] = "5";
    m["six"] = "6";
    m["seven"] = "7";
    m["eight"] = "8";
    m["nine"] = "9";

    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
            num += s[i];
        else
        {
            temp += s[i];
            if (m[temp] != "")
            {
                num += m[temp];
                temp = "";
            }
        }
    }

    answer = stoi(num);

    return answer;
}