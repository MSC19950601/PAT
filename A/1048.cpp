#include <cstdio>
#include <algorithm>

using namespace std;

int a[100010];

int bin(int left, int right, int key) {
    int mid;
    while(left <= right) {
        mid = (left + right)/2;
        if (a[mid] == key) { return mid; }
        else if (a[mid] > key) { right = mid - 1; }
        else { left = mid + 1; }
    }
    return -1;
}

int main() {
    int n,m;
    int i;
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(i = 0; i < n; i++) {
        int pos = bin(0, n-1, m-a[i]);
        if (pos != -1 && i != pos) {
            printf("%d %d",a[i],a[pos]);
            break;
        }      
    } 
    if(i == n ) { printf("No Solution"); } 
    system("pause");
    return 0;
}