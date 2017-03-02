#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 110;

vector<int> tree[N];
int leaf[N] = {0};
int max_h = 1;

void DFS(int index, int h)
{
    max_h = max(h, max_h);
    if (tree[index].size() == 0) {
        leaf[h]++;
        return;
    }
    for(int i = 0; i < tree[index].size(); i++){
        DFS(tree[index][i], h + 1);
    }
}


int main(){
    int n,m;
    int parent, childNum, child;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> parent >> childNum;
        for (int j = 0; j < childNum; j++) {
            cin >> child;
            tree[parent].push_back(child);
        }
    }
    DFS(1,1);
    cout << leaf[1];
    for (int i = 2; i <= max_h; i++) {
        printf(" %d",leaf[i]);
    }
    return 0;
}