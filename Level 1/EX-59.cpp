#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "", t = "";
    
    for(int i = 1; i < food.size(); i++) {
        int n = food[i] / 2;
        for(int j = 0; j < n; j++) {
            answer += to_string(i);
            t = to_string(i) + t;
        }
    }
    
    answer = answer + "0" + t;
    
    return answer;
}
