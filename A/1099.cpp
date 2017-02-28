#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct node{
    int left = -1;
    int right = -1;
    int value;
};

node tree[100];
int num[100];
int index = 0;

void PreTravel(int root)
{
    if (root == -1)
    {
        return;
    }
    PreTravel(tree[root].left);
    tree[root].value = num[index++];
    PreTravel(tree[root].right);
}

void levelTravel(int root)
{
    queue<int> que;
    que.push(root);
    while(!que.empty())
    {
        int ind = que.front();
        que.pop();
        if (ind != root)
            cout << " ";
        cout << tree[ind].value;
        if (tree[ind].left != -1)
            que.push(tree[ind].left);
        if (tree[ind].right != -1)
            que.push(tree[ind].right);
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> tree[i].left >> tree[i].right;
    for(int i = 0; i < n; i++)
        cin >> num[i];
    sort(num,num+n);
    PreTravel(0);
    levelTravel(0);
    return 0;
}