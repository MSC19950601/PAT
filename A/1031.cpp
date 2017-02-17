#include <iostream>
#include <vector>
#include <algorithm>

std::string input;


int main() {

    std::cin >> input;

    int n = input.length();
    int n1,n2;

//    find n1 n2
    for(n2 = 3; n2 <= n; ++n2)
    {
        int temp = n+2-n2;
        if(temp%2 != 0)
            continue;
        n1 = temp/2;
        if(n1 <= n2)
            break;
    }

    for (int i = 0; i < n1 - 1; ++i) {
        std::cout << input.at(i);
        for (int j = 0; j < n2 - 2; ++j) {
            std::cout<< " ";
        }
        std::cout << input.at(n - 1 - i);
        std::cout << std::endl;
    }
    for (int k = n1 - 1; k < n1 + n2 - 1; ++k) {
        std::cout << input.at(k);
    }

    return 0;
}
