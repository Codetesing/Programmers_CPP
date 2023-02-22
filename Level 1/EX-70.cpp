#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int ind1 = 0, ind2 = 0;
    
    for(int i = 0; i < goal.size(); i++) {
        if(cards1[ind1] == goal[i])
            ind1++;
        else if(cards2[ind2] == goal[i])
            ind2++;
        else
            return "No";
    }
    return "Yes";
}
