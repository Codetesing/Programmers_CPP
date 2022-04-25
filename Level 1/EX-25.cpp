#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < n; i++)
    {
        string in = "";

        int temp = arr1[i] | arr2[i];
        int mod = 1 << n - 1;

        for (int j = 1; j <= n; j++)
        {
            if (temp & mod)
                in += '#';
            else
                in += ' ';
            mod = mod >> 1;
        }
        answer.push_back(in);
    }
    return answer;
}