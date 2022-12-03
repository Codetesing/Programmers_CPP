#include <string>
#include <vector>

using namespace std;

string SPLIT(string t) {
    int cnt_a = 0, cnt_b = 0;
    
    for(int i = 0; i < t.size(); i++) {
        if(t[0] == t[i])
            cnt_a++;
        else
            cnt_b++;
        if(cnt_a == cnt_b)
            return t.substr(i + 1);
    }
    
    return "";
}

int solution(string s) {
    int answer = 0;
    
    while(s != ""){
        answer++;
        s = SPLIT(s);
    }
    
    return answer;
}
