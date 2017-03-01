#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 100010;

vector<int> child[maxn];

double p, r;

int n;
int maxdepth = 0;
int maxdepthnum = 0;

void DFS(int index, int depth)
{
    if (child[index].size() == 0) {
        if (depth > maxdepth) {
            maxdepth = depth;
            maxdepthnum = 1;
        } else if (depth == maxdepth) {
            maxdepthnum++;
        }
        return;
    }
    for(int i = 0; i < child[index].size(); i++) { DFS(child[index][i], depth+1); }

}

int main()
{
    int father, root;
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    for (int i = 0; i < n;i++)
    {
        scanf("%d", &father);
        if (father != -1){
            child[father].push_back(i);
        } else {
            root = i;
        }
    }
    DFS(root, 0);
    printf("%.2f %d\n", p * pow(1 + r, maxdepth), maxdepthnum);
    return 0;
}
