#include <iostream>

#include <string>
#include <vector>

using namespace std;

bool IS_RIGHT(string s) {
    if(s[0] == ')')
        return false;
    
    int cnt = 1;
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] == ')')
            cnt--;
        else
            cnt++;
        if(cnt < 0)
            return false;
    }
    
    if(cnt == 0)
        return true;
    else
        return false;
}

string DFS(string s) {
    string u, v;
    
    if(s == "")
        return "";
    
    int cnt = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
            cnt++;
        else
            cnt--;
        
        if(cnt == 0)
        {    
            u = s.substr(0, i + 1);
            if(i == s.size() - 1)
                v = "";
            else
                v = s.substr(i + 1, s.size());
            
            if(IS_RIGHT(u))
                return u + DFS(v);
            else
            {
                string temp = "";
                for(int j = 1; j < u.size() - 1; j++)
                {
                    if(u[j] == ')')
                        temp += '(';
                    else
                        temp += ')';
                }
                
                return '(' + DFS(v) + ')' + temp;
            }
        }
    }
}

string solution(string p) {
    string answer = "";
    
    if(p.size() == 0)
        return "";
    
    answer = DFS(p);
    
    return answer;
}
