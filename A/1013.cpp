#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 1111;
vector<int> G[N];
bool vis[N];

int currentDeletePoint;

void dfs(int v) {
    if (v == currentDeletePoint)
        return;
    vis[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        if(vis[G[v][i]] == false) {
            dfs(G[v][i]);
        }
    }
}

int n, m, k;
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0; i < k; i++){
        scanf("%d", &currentDeletePoint);
        memset(vis, false, sizeof(vis));
        int block = 0;
        for(int city = 1; city <= n; city++){
            if(city != currentDeletePoint && vis[city] == false) {
                dfs(city);
                block++;
            }
        }
        printf("%d\n", block - 1);
    }
    return 0;
}
