#include <iostream> 
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    long long a = 0, b = 0;
    cin >> a >> b;
    int x = (int)(round((b - a) / 100.0));
    int h, m ,s;
    h = x / 3600;
    m = x % 3600 / 60;
    s = x % 60;
    printf("%02d:%02d:%02d\n",h,m,s); 
    return 0;
}

// 法一：通过round()函数（需要引入浮点数）
// 法二：直接判断(C2-C1)%100是否大于等于50，手动进行取整操作。（大    于等于50则(C2-C1)%100+1，否则不+1）
// round()函数原型：double round(double x);

// 输出格式：

// 在一行中输出被测函数运行的时间。运行时间必须按照“hh:mm:ss”（即2位的“时:分:秒”）格式输出；不足1秒的时间四舍五入到秒。

// 所以我们需要用到%0md这种输出格式。 
// （%md可以使不足m为的int型变量以m位进行右对齐输出，高位用空格补齐；若变量本身超过m位，则保持原样。）

// 除法运算时为了“取整”的，所取的整数就是被除数有多少个除数的整数倍。
// 取余运算是为了“取余”的，所取的余数就是被除数除去“取整”后剩下的那些。
