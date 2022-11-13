#include <string>
#include <vector>
#include <map>

using namespace std;

#define MAX 10001

map<string, int> m;
vector<int> money;
int p[MAX] = {0};

void sell(int ind, int m) {
    if(m < 1 || ind == -1)
        return;
    
    money[ind] += m - (m / 10);
    
    sell(p[ind], m / 10);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    for(int i = 0; i < enroll.size(); i++) {
        m[enroll[i]] = i + 1;
        money.push_back(0);
    }
    
    p[0] = -1;
    for(int i = 0; i < referral.size(); i++)
        p[i + 1] = m[referral[i]];
    
    for(int i = 0; i < amount.size(); i++)
        sell(m[seller[i]], amount[i] * 100);
    
    for(int i = 1; i <= enroll.size(); i++)
        answer.push_back(money[i]);
    
    return answer;
}
