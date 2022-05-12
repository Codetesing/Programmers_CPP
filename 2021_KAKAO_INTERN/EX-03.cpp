#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

typedef struct list {
    int num;
    list* prev;
    list* next;
}list;

list* start = NULL;
list* cur = NULL;
list* last_node = NULL;

void push_back_node(int n)
{
    list* temp = (list*)malloc(sizeof(list));
    temp->num = n;
    temp->next = NULL;
    temp->prev = last_node;

    if (start == NULL)
        start = temp;

    if (last_node != NULL)
        last_node->next = temp;

    last_node = temp;
}

void delete_node()
{
    if (cur->prev == NULL)
    {
        cur->next->prev = NULL;
        start = cur->next;
        cur = cur->next;
    }
    else if (cur->next == NULL)
    {
        cur->prev->next = NULL;
        last_node = cur->prev;
        cur = cur->prev;
    }
    else
    {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        cur = cur->next;
    }
}

void append_node(list* node)
{
    int n = node->num;

    if (n < start->num)
    {
        node->next = start;
        node->prev = NULL;
        start->prev = node;
        start = node;
    }
    else if (n > last_node->num)
    {
        push_back_node(n);
    }
    else
    {
        if (n > cur->num)
        {
            for (list* temp = cur; temp->next != NULL; temp = temp->next)
                if (temp->next->num > n)
                {
                    node->prev = temp;
                    node->next = temp->next;

                    temp->next->prev = node;
                    temp->next = node;
                    break;
                }
        }
        else
        {
            for (list* temp = cur; temp->prev != NULL; temp = temp->prev)
                if (temp->prev->num < n)
                {
                    node->prev = temp->prev;
                    node->next = temp;

                    temp->prev->next = node;
                    temp->prev = node;
                    break;
                }
        }
    }
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    int size = n - 1;
    vector<list*> deleted;
    //vector<int> deleted;

    for (int i = 0; i < n; i++)
    {
        answer += "X";
        push_back_node(i);
        if (i == k)
            cur = last_node;
    }

    int cnt = 0;
    int end_ind = cmd.size() - 1;
    for (int i = cmd.size() - 1; i >= 0; i--)
    {
        char opt = cmd[i][0];
        if (opt == 'C')
        {
            if (cnt == 0)
            {
                end_ind = i;
                break;
            }
            else
                cnt--;
        }
        else if (opt == 'Z')
            cnt++;
    }

    for (int i = 0; i <= end_ind; i++)
    {
        cnt = 0;
        char opt = cmd[i][0];
        if (opt == 'U')
        {
            int num = stoi(cmd[i].substr(2, cmd[i].size() - 2));
            for (int j = 0; j < num; j++)
                cur = cur->prev;
        }
        else if (opt == 'D')
        {
            int num = stoi(cmd[i].substr(2, cmd[i].size() - 2));
            for (int j = 0; j < num; j++)
                cur = cur->next;
        }

        else if (opt == 'C')
        {
            deleted.push_back(cur);
            delete_node();
        }
        else if (opt == 'Z')
        {
            list* recovered = deleted[deleted.size() - 1];
            deleted.pop_back();
            append_node(recovered);
        }
    }

    for (list* temp = start; temp != NULL; temp = temp->next)
        answer[temp->num] = 'O';

    for (list* temp = start->next; temp != NULL; start = temp, temp = start->next)
        free(start);
    free(start);

    return answer;
}