#include <iostream>
#include <vector>
#include <algorithm>

int R,G,B;

char int2char(int n)
{
    if(n <= 9)
        return '0' + n;
    else
        return 'A' + (n - 10);
}

std::string convertMars(int value)
{
    std::string temp;
    int yushu;
    int radix = 13;
    while(1)
    {
        yushu = value % radix;
        temp.insert(temp.begin(),int2char(yushu));
        value = value / radix;
        if(value < radix){
            temp.insert(temp.begin(),int2char(value));
            break;
        }
    }

    return temp;
}


int main() {

    std::cin >> R >> G >> B;
    std::string MR = convertMars(R);
    std::string MG = convertMars(G);
    std::string MB = convertMars(B);
    std::cout << "#" << MR << MG << MB;
    return 0;
}
