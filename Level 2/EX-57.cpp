#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ind;

bool compare(vector<int> a, vector<int> b) {
    if(a[ind] == b[ind])
        return a[0] > b[0];
    else
        return a[ind] < b[ind];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    ind = col - 1;
    
    sort(data.begin(), data.end(), compare);
    
    for(int i = row_begin; i <= row_end; i++) {
        int s = 0;
        
        for(int j = 0; j < data[i - 1].size(); j++)
            s += data[i - 1][j] % i;
        
        if(i == row_begin)
            answer = s;
        else
            answer = answer ^ s;
    }
    
    return answer;
}
