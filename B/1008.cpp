#include <iostream>

using namespace std;

int a[105];
int main(){
    int n, strike;
    cin >> n >> strike;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    strike = strike % n;
    int count = 0;
    for (int i = n - strike; i < n; i++){
        count++;
        cout << a[i];
        if (count < n){
            cout << " ";
        }
    }
    for (int i = 0; i < n - strike; i++){
        count++;
        cout << a[i];
        if (count < n){
            cout << " ";
        }
    }
    return 0;
}

// 本方法的关键就在数组元素右移那两个for循环处，第一个for循环控制移动次数（该题就是M次），第二个for循环用来完成数组中所有元素的循环右移操作。（M==0时可以不特判）

// 还有个地方需要注意，题目并没有保证M<N,所以需要拿到N,M之后，需要做M=M%N操作，以方便后续算法。