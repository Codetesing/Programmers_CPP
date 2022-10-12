#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int num_X[10] = {0};
    int num_Y[10] = {0};
    
    for(int i = 0; i < X.size(); i++)
        num_X[X[i] - '0']++;
    for(int i = 0; i < Y.size(); i++)
        num_Y[Y[i] - '0']++;
    
    for(int i = 9; i >= 0; i--)
    {
        int temp = min(num_X[i], num_Y[i]);
        answer.append(temp, i + '0');
    }
    
    if(answer.empty())
        answer = "-1";
    else if(answer[0] == '0')
        answer = "0";
    
    return answer;
}
