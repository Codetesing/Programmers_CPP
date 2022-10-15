#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> temp;
    
    for(int i = 0; i < want.size(); i++)
        temp[want[i]] = i + 1;

    for(int i = 0; i <= discount.size() - 10; i++) {
        vector<int> n = number;
        bool flag = true;

        for(int j = 0; j < 10; j++)
        {
            int num = temp[discount[i + j]] - 1;
            
            if(num == -1)
            {
                flag = false;
                break;
            }
            
            n[num]--;
            
            if(n[num] < 0)
            {    
                flag = false;
                break;
            }
        }
        
        if(flag)
            answer++;
    }
    
    return answer;
}