#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ind = -1;

bool cmp(vector<int> a, vector<int> b) {
    if(a[ind] < b[ind]) {
        return true;
    } else {
        return false;
    }
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    if(ext == "code") {
        ind = 0;
    } else if(ext == "date") {
        ind = 1;
    } else if(ext == "maximum") {
        ind = 2;
    } else if(ext == "remain") {
        ind = 3;
    }
    
    for(int i = 0; i < data.size(); i++) {
        if(data[i][ind] < val_ext) {
            answer.push_back(data[i]);
        }
    }
    
    if(sort_by == "code") {
        ind = 0;
    } else if(sort_by == "date") {
        ind = 1;
    } else if(sort_by == "maximum") {
        ind = 2;
    } else if(sort_by == "remain") {
        ind = 3;
    }
    
    sort(answer.begin(), answer.end(), cmp);
    
    return answer;
}
