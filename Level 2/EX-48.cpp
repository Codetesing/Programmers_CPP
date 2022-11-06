#include <string>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    vector<int> arr;
    arr.push_back(0);
    
    for(int i = 0; i < order.size(); i++) {
        if(order[answer] == i + 1)
            answer++;
        else if(arr.back() == order[answer])
        {
            answer++;
            arr.pop_back();
            i--;
        }
        else
            arr.push_back(i + 1);
    }
    
    while(arr.size() != 1) {
        if(arr.back() == order[answer])
        {
            answer++;
            arr.pop_back();
        }
        else
            break;
    }
    
    return answer;
}
