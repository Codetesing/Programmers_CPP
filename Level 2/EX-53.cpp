#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

vector<string> SPLIT(string a, char d) {
    vector<string> t;
    stringstream ss(a);
    string temp;
    
    while(getline(ss, temp, d))
        if(temp != "and")
            t.push_back(temp);
    
    return t;
}

bool IS_RIGHT(vector<string> q, vector<string> i) {
    for(int k = 0; k < q.size() - 1; k++) {
        if(q[k] == "-")
            continue;
        if(q[k] != i[k])
            return false;
    }
    
    if(stoi(q[q.size() - 1]) <= stoi(i[i.size() - 1]))
        return true;
    else
        return false;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    map<string, vector<int>> m;
    
    for(int i = 0; i < info.size(); i++) {
        vector<string> info_key = SPLIT(info[i], ' ');
        
        for(int j = 0; j < 16; j++) {
            string t = "";
            for(int k = 0; k < 4; k++) {
                t += (j & (1 << k) ? info_key[k] : "-");
            }
            m[t].push_back(stoi(info_key[4]));
        }
    }
    
    for(auto &it : m)
        sort(it.second.begin(), it.second.end());
    
    for(int i = 0; i < query.size(); i++) {
        vector<string> query_key = SPLIT(query[i], ' ');
        string t = "";
        
        for(int j = 0; j < 4; j++)
            t += query_key[j];
        
        vector<int> temp = m[t];
        int cnt = temp.end() - lower_bound(temp.begin(), temp.end(), stoi(query_key[4]));
        answer.push_back(cnt);
    }
    
    return answer;
}
