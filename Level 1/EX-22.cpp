#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int W = 0, H = 0;

    for (int i = 0; i < sizes.size(); i++)
    {
        if (W < max(sizes[i][0], sizes[i][1]))
            W = max(sizes[i][0], sizes[i][1]);
        if (H < min(sizes[i][0], sizes[i][1]))
            H = min(sizes[i][0], sizes[i][1]);
    }

    return W * H;
}