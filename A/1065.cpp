#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    int i = 1;
    while(T-- > 0){
        bool flag = false;
        long long A;
        long long B;
        long long C;
        cin >> A >> B >> C;
        long long res = A + B;
        if( A > 0 && B > 0){
            if (res <= 0){
                flag = true;//?
            }else {
                if (res > C){
                    flag = true;
                }
            }
        }else if(A < 0 && B < 0){
            if (res >= 0){
                flag = false;
            }else {
                if (res > C){
                    flag = true;
                }
            }
        }else {
            if (res > C){
                flag = true;
            }
        }

        if(flag){
            cout << "Case #" << i << ": true" << endl;
        }else{
            cout << "Case #" << i << ": false" << endl;
        }
        i++;
    }
    return 0;
}

// 首先需要知道一下，这个题目A,B,C的取值范围应该是[-2^63, 2^63)左闭右开，这是经过测试发现后台数据中没有2^63这组数据。 
// 这样一来，我们就可以直接用long long型变量来存储输入的数据。long long 型变量的取值范围是[-2^63,2^63-1]。 
// 在《计算机组成原理》中有两个概念：正溢出和负溢出。

// 正溢出：两个整数相加的结果超过了数据类型所能表示的最大范围，结果为负数
// 负溢出：两个负数相加的结果超过了数据类型所能表示的最小范围，结果为正数（包括0）