#define MUL 65536

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    vector<string> set1;
    vector<string> set2;

    for (int i = 0; i < str1.size() - 1; i++)
        if (isalpha(str1[i]))
        {
            if (isalpha(str1[i + 1]))
            {
                string temp = "";
                temp += (char)tolower(str1[i]);
                temp += (char)tolower(str1[i + 1]);
                set1.push_back(temp);
            }
            else
                i++;
        }

    for (int i = 0; i < str2.size() - 1; i++)
        if (isalpha(str2[i]))
        {
            if (isalpha(str2[i + 1]))
            {
                string temp = "";
                temp += (char)tolower(str2[i]);
                temp += (char)tolower(str2[i + 1]);
                set2.push_back(temp);
            }
            else
                i++;
        }

    sort(set1.begin(), set1.end());
    sort(set2.begin(), set2.end());

    int common = 0;
    int uncomm = set1.size() + set2.size();
    double J;

    if (uncomm == 0)
        J = 1;

    else
    {
        while (!set1.empty() && !set2.empty())
        {
            if (set1[0] == set2[0])
            {
                common++;
                set1.erase(set1.begin());
                set2.erase(set2.begin());
            }
            else if (set1[0] > set2[0])
                set2.erase(set2.begin());
            else
                set1.erase(set1.begin());
        }

        uncomm -= common;
        J = (double)common / uncomm;
    }

    answer = J * MUL;

    return answer;
}