#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> temp;
    int num = 1, turn = 1;
    char last = words[0][0];

    for (int i = 0; i < words.size(); i++)
    {
        string word = words[i];
        
        if (last != word[0])
        {
            answer.push_back(num);
            answer.push_back(turn);
            break;
        }

        if (temp[word] == 0)
            temp[word] = num;
        else
        {
            answer.push_back(num);
            answer.push_back(turn);
            break;
        }

        num++;
        last = word[word.size() - 1];

        if (num == n + 1)
        {
            num = 1;
            turn++;
        }
    }

    if (answer.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}