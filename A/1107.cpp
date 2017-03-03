#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1010;

int father[N];
int isRoot[N];
int course[N];

int findfather(int x) {
    int a = x;
    while (x != father[x]) {
        x = father[x];
    }
    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b) {
    int faA = findfather(a);
    int faB = findfather(b);
    if (faA != faB) {
        father[faA] = faB;
    }
}

void init(int n) {
    for (int i = 0; i <= n; i++) {
        father[i] = i;
        isRoot[i] = false;
    }
}

bool cmp(int a, int b) { return a > b; }


int main() {
    int n, k ,h;
    scanf("%d", &n);
    init(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d:", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &h);
            if (course[h] == 0) {
                course[h] = i;
            }
            Union(i, findfather(course[h]));
        }
    }
    for (int i = 1; i <= n; i++) {
        isRoot[findfather(i)]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (isRoot[i] != 0) {
            ans++;
        }
    }
    sort(isRoot + 1, isRoot + n + 1, cmp);
    for (int i = 1; i <= ans; i++) {
        printf("%d", isRoot[i]);
        if (i < ans) { printf(" "); }
    }
    return 0;
}