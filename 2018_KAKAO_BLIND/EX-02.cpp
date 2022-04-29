#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < n; i++)
    {
        string in = "";
        int temp = arr1[i] | arr2[i];

        for (int j = 0; j < n; j++)
        {
            if (temp & (1 << j))
                in = '#' + in;
            else
                in = ' ' + in;
        }
        answer.push_back(in);
    }
    
    return answer;
}