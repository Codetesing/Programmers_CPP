#include <string>
#include <vector>

using namespace std;

int TRANS_TIME(string cur) {
    int year = stoi(cur.substr(0, 4));
    int month = stoi(cur.substr(5, 2));
    int day = stoi(cur.substr(8, 2));
    
    return ((year - 2000) * 12 * 28) + (month * 28) + day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> alpha(26, 0);
    int today_time = TRANS_TIME(today);
    
    for(int i = 0; i < terms.size(); i++) {
        alpha[terms[i][0] - 'A'] = stoi(terms[i].substr(2));
    }
    
    for(int i = 0; i < privacies.size(); i++) {
        string cur = privacies[i].substr(0, 10);
        int period = alpha[privacies[i][11] - 'A'];
        int next = TRANS_TIME(cur) + period * 28;
        
        if(today_time >= next)
          answer.push_back(i + 1);
    }
    
    return answer;
}
