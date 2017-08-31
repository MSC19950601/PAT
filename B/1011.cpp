#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    int i = 1;
    while(T-- > 0){
        long long A;
        long long B;
        long long C;
        cin >> A >> B >> C;
        if (A + B > C) {
            cout << "Case #" << i << ": true" << endl;
        }else{
            cout << "Case #" << i << ": false" << endl;
        }
        i++;
    }
    return 0;
}