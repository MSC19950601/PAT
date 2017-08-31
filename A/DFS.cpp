const int MAXV = ?;
const int INF = 10000000000;

// 邻接矩阵
int n, G[MAXV][MAXV];

bool vis[MAXV] = {false};

void DFS(int u, int depth) {
    vis[u] = true;
    for(int i = 0; i < n; i++){
        if(vis[i] == false && G[u][i] != INF) {
            DFS(i, depth + 1);
        }
    }
}

void DFStrval() {
    for(int u = 0; u < n; u++) {
        if(vis[u] == false) {
            DFS(u, 1);
        }
    }
}