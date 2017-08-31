#include <cstdio>

using namespace std;

int a[10005];
int b[10005];
int main() {
    int cnt = 0;
    int bitInx = 0;
    while(scanf("%d",&a[cnt++]) != EOF);
    cnt--;
    for (int i = 0; i < cnt; i++){
        if(i % 2 == 0){
            b[i] =  a[i] * a[i+1]; 
        }else {
            b[i] = a[i] - 1;
        }
        bitInx = i;
    }
    if (bitInx == 1 && b[0] == 0) {
        printf("0 0\n");
    }else{
        for (int i = 0; i < cnt; i++){
            if(i%2 == 0 && b[i] == 0) {
                break;
            }
            if(i==0){
                printf("%d",b[i]);
            }else{
                printf(" %d",b[i]);
            }
        }printf("\n");
    }
    
    return 0;
}