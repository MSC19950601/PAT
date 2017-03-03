#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;        

int n,p;
int data[maxn];

int main() {
    scanf("%d%d",&n, &p);
    for (int i = 0; i < n; i++) {
        scanf("%d",&data[i]);
    }
    sort(data,data + n);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int j = upper_bound(data + i + 1, data + n, (long long)data[i] * p) - data;
        ans = max(ans, j-i);
    }
    printf("%d",ans);
    return 0;
}