#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n;
    cin >> n;
    stringstream ss;
    ss << n;
    string n_str = ss.str();
    int l = n_str.size();
    if(l == 1){
        for (int i = 1; i <= ((int)n_str[0] - 48); i++)
            cout << i;
    }
    if(l == 2){
        for (int i = 0; i < ((int)n_str[0] - 48); i++)
            cout << "S";
        for (int i = 1; i <= ((int)n_str[1] - 48); i++)
            cout << i;
    }
    if(l == 3){
        for (int i = 0; i < ((int)n_str[0] - 48); i++)
            cout << "B";
        for (int i = 0; i < ((int)n_str[1] - 48); i++)
            cout << "S";
        for (int i = 1; i <= ((int)n_str[2] - 48); i++)
            cout << i;
    }
    return 0;
}