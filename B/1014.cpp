#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

map<char, string> DAY = {
    {'A', "MON"},
    {'B', "TUE"},
    {'C', "WED"},
    {'D', "THU"},
    {'E', "FRI"},
    {'F', "SAT"},
    {'G', "SUN"}
};

map<char, string> HOUR = {
    {'0', "00"},
    {'1', "01"},
    {'2', "02"},
    {'3', "03"},
    {'4', "04"},
    {'5', "05"},
    {'6', "06"},
    {'7', "07"},
    {'8', "08"},
    {'9', "09"},
    {'A', "10"},
    {'B', "11"},
    {'C', "12"},
    {'D', "13"},
    {'E', "14"},
    {'F', "15"},
    {'G', "16"},
    {'H', "17"},
    {'I', "18"},
    {'J', "19"},
    {'K', "20"},
    {'L', "21"},
    {'M', "22"},
    {'N', "23"}
};

// set<char> findSameChar(string str1, string str2){
//     set<char> tree;
//     set<char> res;
//     for(int i = 0; i < str1.size(); i++) {
//         if(str1.at(i) >= 'A' && str2.at(i) <= 'Z'){
//             tree.insert(str1.at(i));
//         }
//     }
//     for(int i = 0; i < str2.size(); i++) {
//          if(tree.find(str2.at(i)) != tree.end()){
//              res.insert(str2.at(i));
//          }
//     }
//     return res;
// }

// set<char> findSameChar2(string str1, string str2){
//     set<char> tree;
//     set<char> res;
//     for(int i = 2; i < str1.size(); i++) {
//         if(str1.at(i) >= 'a' && str2.at(i) <= 'z'){
//             tree.insert(str1.at(i));
//         }
//     }
//     for(int i = 2; i < str2.size(); i++) {
//          if(tree.find(str2.at(i)) != tree.end()){
//              res.insert(str2.at(i));
//          }
//     }
//     return res;
// }

// int main() {

//     string str1, str2, str3, str4;
//     cin >> str1 >> str2 >> str3 >> str4;
//     set<char> res1 = findSameChar(str1, str2);
//     set<char> res2 = findSameChar2(str3, str4);
//     for(set<char>::iterator it = res1.begin(); it != res1.end(); it++){
//         cout << *it << endl;
//     }
//     for(set<char>::iterator it = res2.begin(); it != res2.end(); it++){
//         cout << *it << endl;
//     }
//     return 0;
// }

int main() {

    string str1, str2, str3, str4;
    cin >> str1 >> str2 >> str3 >> str4;
    vector<char> res1;
    int res2;
    for(int i = 0; i < min(str1.length(), str2.length()); i++) {
        if (str1.at(i) == str2.at(i)) {
            res1.push_back(str1.at(i));
        }
    }

    for(int i = 0; i < min(str3.length(), str4.length()); i++) {
        if (str3.at(i) == str4.at(i) && isalpha(str3.at(i))) {
            res2 = i;
            break;
        }
    }
    char D = ' ';
    char H = ' ';
    int i;
    for(i = 0; i < res1.size(); i++){
        if(res1[i] >= 'A' && res1[i] <= 'G'){
            D = res1[i];
            break;
        }
    }
    for(int j = i + 1; j < res1.size(); j++){
        if((res1[j] >= 'A' && res1[j] <= 'N') || (res1[j] >= '0' && res1[j] <= '9')){
            H = res1[j];
            break;
        }
    }
    // cout << D << H << endl;
    if(res2 < 10 && D != ' ' && H != ' '){
        cout << DAY[D] << " " << HOUR[H] << ":" << "0" << res2 << endl; 
    }else if( res2 >= 10 && D != ' ' && H != ' ' ){
        cout << DAY[D] << " " << HOUR[H] << ":" << res2 << endl; 
    }
    return 0;
}