#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 110;
vector<int> tree[maxn];

int hashtable[maxn] = {0};

void DFS(int index, int depth) {
  hashtable[depth]++;
  for (int i = 0; i < tree[index].size(); i++) {
    DFS(tree[index][i], depth + 1);
  }
}

int main() {
  int n, m, parent, child, k;
  scanf("%d%d",&n,&m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &parent, &k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &child);
      tree[parent].push_back(child);
    }
  }
  DFS(1, 1);
  int maxlevel = -1, maxvalue = 0;
  for (int i = 1; i < maxn; i++) {
    if (hashtable[i] > maxvalue) {
      maxvalue = hashtable[i];
      maxlevel = i;
    }
  }
  printf("%d %d\n", maxvalue, maxlevel);
  return 0;
}