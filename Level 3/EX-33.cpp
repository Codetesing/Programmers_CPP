#include <string>
#include <vector>

using namespace std;

int time_to_int(string a) {
    int s = 0;
    
    s += stoi(a.substr(0, 2)) * 3600;
    s += stoi(a.substr(3, 2)) * 60;
    s += stoi(a.substr(6, 2));
    
    return s;
}

string int_to_time(int a) {
    string s = "";
    int h = a / 3600;
    a %= 3600;
    int m = a / 60;
    int ss = a % 60;
    
    if(h < 10) s += "0";
    s += to_string(h) + ":";
    if(m < 10) s += "0";
    s += to_string(m) + ":";
    if(ss < 10) s += "0";
    s += to_string(ss);
    
    return s;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    
    int n = time_to_int(play_time);
    int m = time_to_int(adv_time);
    vector<long long> time_line(n + 1, 0);
    
    for(auto i:logs) {
        int start = time_to_int(i.substr(0, 8));
        int end = time_to_int(i.substr(9, 8));
        
        time_line[start]++;
        time_line[end]--;
    }
    
    for(int i = 1; i <= n; i++)
        time_line[i] += time_line[i - 1];
    
    for(int i = 1; i <= n; i++)
        time_line[i] += time_line[i - 1];
    
    int max_time = 0;
    long long max_view = 0;
    
    if(time_line[m - 1] != 0)
        max_view = time_line[m - 1];
    
    for(int i = m; i <= n; i++) {
        if(max_view < time_line[i] - time_line[i - m]) {
            max_time = i - m + 1;
            max_view = time_line[i] - time_line[i - m];
        }
    }
    
    answer = int_to_time(max_time);
    
    return answer;
}
