#include <string>
#include <vector>
#include <map>

using namespace std;

bool find_in(string s, char a) {
    for(int i = 0; i < s.size(); i++)
        if(s[i] == a)
            return true;
    
    return false;
}

string solution(string s, string skip, int index) {
    string answer = "";
    map<char, char> m;
    
    for(char t = 'a'; t <= 'z'; t++) {
        int cnt = 0;
        char cur = t;
        
        while(cnt != index) {
            if(cur == 'z')
                cur = 'a' - 1;
            
            if(!find_in(skip, ++cur))
                cnt++;
        }
        
        m[t] = cur;
    } 
    
    for(int i = 0; i < s.size(); i++)
        answer = answer + m[s[i]];
    
    return answer;
}
