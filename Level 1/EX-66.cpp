#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> t;
    
    for(int i = 0; i < ingredient.size(); i++) {
        if(ingredient[i] == 1) {
            if(t.size() >= 3 && *(t.end() - 1) == 3 && *(t.end() - 2) == 2 && *(t.end() - 3) == 1) {
                answer++;
                t.erase(t.end() - 3, t.end());
            }
            else
                t.push_back(1);
        }
        else
            t.push_back(ingredient[i]);
    }
    
    return answer;
}
