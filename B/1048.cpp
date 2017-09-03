#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {

    stringstream out;

    string A, B;
    cin >> A >> B;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    int len = min(A.length(), B.length());
    for(int i = 1; i <= len; i++) {
        if(i%2 == 0){
            int res = ((int)B.at(i-1) - 48) - ((int)A.at(i-1) - 48);
            if (res < 0){
                res += 10;
                out << res;
            }else {
                out << res;
            }
        }else{
            int mod = (((int)A.at(i-1) - 48) + ((int)B.at(i-1) - 48)) % 13;
            if (mod == 10){
                out << "J";
            }else if(mod == 11){
                out << "Q";
            }else if(mod == 12){
                out << "K";
            }else{
                out << mod;
            }
        }
    }
    if(len < B.length()){
        for(int i = len; i < B.length(); i++){
            out << B.at(i);
        }
    }
    // if(len < A.length()) {
    //     for(int i = len; i < A.length(); i++){
    //         out << A.at(i);
    //     }
    // }
    string result = out.str();
    reverse(result.begin(), result.end());
    // cout << A << " " << B << endl;
    cout << result << endl;
    return 0;    
}