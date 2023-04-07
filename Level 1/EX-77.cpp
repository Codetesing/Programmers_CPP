#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer = players;
    map<string, int> m;
    
    for(int i = 0; i < players.size(); i++)
        m[players[i]] = i;
    
    for(int i = 0; i < callings.size(); i++) {
        int ind = m[callings[i]];
        string s = answer[ind - 1];
        m[callings[i]]--;
        m[s]++;
        
        swap(answer[ind], answer[ind - 1]);
    }
    
    return answer;
}
