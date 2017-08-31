#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>

using namespace std;

int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char trans[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int main() {

    int n;
    scanf("%d", &n);
    bool flag = true;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        int j, last = 0;
        for(j = 0; j < 17; j++) {
            if(!(str[j] >= '0' && str[j] <= '9')) 
                break;
            last = last + (str[j] - '0') * weight[j];
        }
        if(j < 17){
            flag = false;
            cout << str << endl;
        }else {
            if(trans[last % 11] != str[17]){
                flag = false;
                cout << str << endl;
            }
        }
    }
    if(flag)
        cout << "All passed" << endl;
    return 0;
}
