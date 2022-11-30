#include <string>
#include <vector>

using namespace std;

bool CAN_SP(string s) {
    int prev = 0;
    for(int i=0; i<s.length(); i++) {
        if(s.substr(i,3) == "aya" && prev != 1) { 
            prev = 1; 
            i += 2; 
        }
        else if(s.substr(i,2) == "ma" && prev != 2) {
            prev = 2; 
            i += 1; 
        }
        else if(s.substr(i,3)=="woo" && prev != 3) { 
            prev = 3; 
            i += 2; 
        }
        else if(s.substr(i,2)=="ye" && prev != 4) { 
            prev = 4; 
            i += 1; 
        }
        else return false;
    }
    return true;
}

int solution(vector<string> babbling)
{
    int answer=0;

    for(int i = 0; i < babbling.size(); i++)
        if(CAN_SP(babbling[i]))
            answer++;

    return answer;
}
