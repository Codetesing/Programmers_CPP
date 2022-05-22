#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> temp;

    for (int i = 0; i < numbers.size(); i++)
        temp.push_back(to_string(numbers[i]));

    string answer = "";

    sort(temp.begin(), temp.end(), cmp);

    if (temp[0] == "0")
        return "0";

    for (int i = 0; i < temp.size(); i++) 
        answer += temp[i];

    return answer;
}
