#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int a[100005];
// 大样本超时
int main(){
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &a[i]);

    int M;
    scanf("%d", &M);
    while(M-- > 0){
        int start, end;
        scanf("%d%d", &start, &end);
        if (start == end){
            printf("0\n");
            continue;
        }
        if (start > end){
            int tmp = start;
            start = end;
            end = tmp;
        }
        int distance1 = 0;
        for(int i = start; i < end; i++){
            distance1 += a[i];
        }
        int distance2 = 0;
        for(int i = 0; i < start; i++){
            distance2 += a[i];
        }
        for(int i = end; i <= N; i++){
            distance2 += a[i];
        }
        int ans = min(distance1, distance2);
        printf("%d\n", ans);

    }
    return 0;
}

// 思路：用整型数组dis[i]表示从1号节点顺时针走到i+1号节点的路径长度（则dis[1]为0），然后用整型变量sum记录走一圈的路径长度，这样一来，题目需要求的就是从节点A到节点B的最短路径，即dis[B]-dis[A]和sum-(dis[A]-dis[B])两者中的较小的一个。

// 注意：由于题目没有保证B节点序号一定大于A节点，故需要在A节点序号大于B节点序号的时候做一下交换。

// #include<cstdio>
// #include<algorithm>

// using namespace std;

// int main(){

//     int N;
//     scanf("%d",&N);

//     int A[N];
//     int sum = 0;
//     int dis[N];
//     dis[0] = 0;
//     for(int i = 0; i < N; i++){
//         scanf("%d",&A[i]);
//         sum += A[i];
//         dis[i+1] = sum;
//     }

//     int M;
//     scanf("%d",&M);

//     int left, right;
//     for(int i = 0; i < M; i++){
//         scanf("%d %d",&left, &right);
//         left-=1; right-=1;
//         if(left > right){
//             int temp = left;
//             left = right;
//             right = temp;
//         }

//         int x = dis[right]-dis[left];

//         printf("%d\n",min((sum-x), x));
//     }

//     return 0;
// } 