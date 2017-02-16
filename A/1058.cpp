#include <iostream>
#include <vector>
#include <algorithm>


int main() {

    int a,b,c,d,e,f;

    scanf("%d.%d.%d %d.%d.%d",&a,&b,&c,&d,&e,&f);

    int t1 = (c+f)/29;
    int final3 = (c+f)%29;

    int t2 = (b+e+t1)/17;
    int final2 = (b+e+t1)%17;

    int final1 = a+d+t2;

    std::cout << final1 << "." << final2 << "." << final3 ;


    return 0;
}
