#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    for(answer = 0; ; answer++) {
        if(wallet[0] >= bill[0] && wallet[1] >= bill[1]) {
            break;
        } else if(wallet[0] >= bill[1] && wallet[1] >= bill[0]) {
            break;
        }
        
        if(bill[0] > bill[1]) {
            bill[0] /= 2;
        } else {
            bill[1] /= 2;
        }
    }
    
    return answer;
}
