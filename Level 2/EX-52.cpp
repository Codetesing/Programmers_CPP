#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

bool possi(vector<int> vec,int now){
    for(int i = 0; i < vec.size(); i++)
        if((vec[i] & now) == vec[i])
            return false;

    return true;
}

int solution(vector<vector<string>> relation) {
    int rowSize = (int)relation.size(); 
    int colSize = (int)relation[0].size();
    vector<int> ans;
    
    for(int i = 1; i < (1<<colSize); i++){
        set<string> s;

        for(int j = 0; j < rowSize; j++){
            string now = "";

            for(int k = 0; k < colSize; k++){
                if(i & (1<<k))
                    now += relation[j][k];
            }
            s.insert(now);
        }

        if(s.size() == rowSize && possi(ans,i))
            ans.push_back(i);
    }

    return (int)ans.size();
}
