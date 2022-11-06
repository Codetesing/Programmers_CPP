#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> Collatz;
    vector<double> S;
    
    Collatz.push_back(k);
    while(k != 1) {
        if(k % 2 == 0)
            k /= 2;
        else
            k = k * 3 + 1;
        Collatz.push_back(k);
    }
    
    for(int i = 0; i < Collatz.size() - 1; i++) {
        int x = min(Collatz[i], Collatz[i + 1]);
        int y = max(Collatz[i], Collatz[i + 1]);
        
        double temp = (y - x) * 0.5;
        temp += x;
        
        S.push_back(temp);
    }
    
    int start = 0, end = Collatz.size() - 1;
    for(int i = 0; i < ranges.size(); i++) {
        int a = start + ranges[i][0];
        int b = end + ranges[i][1];
        
        if(a == b) {
            answer.push_back(0.0);
            continue;
        }
        else if(a > b) {
            answer.push_back(-1.0);
            continue;
        }
        
        else {
            double sum = 0.0;
            for(int j = a; j < b; j++)
                sum += S[j];
            answer.push_back(sum);
        }
    }
    
    return answer;
}
