#include <string>
#include <vector>

using namespace std;

// RT, CF, JM, AN   < 동의  비동의 >

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    string selection[4] = {"RT", "CF", "JM", "AN"};
    int n = survey.size();
    int cnt[26] = {0};
    
    for(int i = 0; i < n; i++){
        int score = choices[i] - 4;
        
        if(score < 0)
            cnt[survey[i][0] - 'A'] += score * -1;
        else
            cnt[survey[i][1] - 'A'] += score;
    }
    
    for(int i = 0; i < 4; i++) {
        if(cnt[selection[i][0] - 'A'] > cnt[selection[i][1] - 'A'])
            answer = answer + selection[i][0];
        else if (cnt[selection[i][0] - 'A'] < cnt[selection[i][1] - 'A'])
            answer = answer + selection[i][1];
        else
        {
            if(selection[i][0] > selection[i][1])
                answer = answer + selection[i][1];
            else
                answer = answer + selection[i][0];
        }
    }
    
    return answer;
}
