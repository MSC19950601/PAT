#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

int a[10];

int main() {
    string input;
    cin >> input;
    for(int i = 0; i < input.size(); i++){
        a[((int)input.at(i) - 48)]++;
    }
    for(int i = 0; i <= 9; i++) {
        if(a[i] != 0)
            printf("%d:%d\n", i, a[i]);
    }
    return 0;
}