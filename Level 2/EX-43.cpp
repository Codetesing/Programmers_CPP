#include <string>
#include <vector>

using namespace std;

vector<vector<int>> hanoi;

void Hanoi(int start, int end, int n) {
    if (n == 1) 
    {
        hanoi.push_back({ start, end });
        return;
    }

    Hanoi(start, 6 - start - end, n - 1);
    hanoi.push_back({ start, end });
    Hanoi(6 - start - end, end, n - 1);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;

    Hanoi(1, 3, n);
    
    answer = hanoi;

    return answer;
}