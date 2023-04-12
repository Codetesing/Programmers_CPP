#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct NODE {
    int n;
    NODE* left;
    NODE* right;
} NODE;

vector<vector<int>> info;
vector<int> pre;
vector<int> post;

void preorder(NODE* cur) {
    if(cur == NULL) return;
    
    pre.push_back(cur->n);
    preorder(cur->left);
    preorder(cur->right);
}

void postorder(NODE* cur) {
    if(cur == NULL) return;
    
    postorder(cur->left);
    postorder(cur->right);
    post.push_back(cur->n);
}

NODE* insert(int start, int end) {
    if(start > end)
        return NULL;
    
    int max_y = info[start][1];
    int max_ind = start;
    for(int i = start + 1; i <= end; i++)
        if(max_y < info[i][1]) {
            max_y = info[i][1];
            max_ind = i;
        }
    
    NODE* cur = new NODE();
    cur->n = info[max_ind][2];
    cur->left = insert(start, max_ind - 1);
    cur->right = insert(max_ind + 1, end);
    
    return cur;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    for(int i = 0; i < nodeinfo.size(); i++)
        nodeinfo[i].push_back(i + 1);
    
    sort(nodeinfo.begin(), nodeinfo.end());
    info = nodeinfo;
    
    NODE* graph = insert(0, nodeinfo.size() - 1);
    
    preorder(graph);
    postorder(graph);
    
    answer.push_back(pre);
    answer.push_back(post);
    
    return answer;
}
