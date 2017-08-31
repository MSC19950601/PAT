#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main() {

    long long A;
    int Da;
    long long B;
    int Db;

    cin >> A >> Da >> B >> Db;

    stringstream ss1;
    stringstream ss2;
    ss1 << A;
    string A_str = ss1.str();
    ss2 << B;
    string B_str = ss2.str();

    int num_Da = 0, num_Db = 0;
    for(int i = 0; i < A_str.size(); i++){
        if (((int)A_str.at(i) - 48) == Da)
            num_Da++;
        else
            continue;
    }
    for(int i = 0; i < B_str.size(); i++){
        if (((int)B_str.at(i) - 48) == Db)
            num_Db++;
        else
            continue;
    }
    // cout << num_Da << " " << num_Db << endl;        
    long long ans = 0;

    if (Da == 0 && Db == 0){
        ans = 0;
    }else if(Da == 0 && Db != 0){
        if(num_Db == 0)
            ans = 0;
        else{
            for (int i = num_Db; i > 0; i--){
                ans += Db * pow(10, i-1);
            }
        }
    }else if(Da != 0 && Db == 0){
        if (num_Da == 0)
            ans = 0;
        else {
            for (int i = num_Da; i > 0; i--){
                ans += Da * pow(10, i-1);
            }
        }
    }else {
        long long ans1 = 0;
        long long ans2 = 0;
        if (num_Da != 0) {
            for (int i = num_Da; i > 0; i--){
                ans1 += Da * pow(10, i-1);
            }
        }
        if (num_Db != 0) {
            for (int i = num_Db; i > 0; i--){
                ans2 += Db * pow(10, i-1);
            }
        }
        ans = ans1 + ans2;
    }
    cout << ans << endl;
    return 0;
}

// #include<stdio.h>

// int main(){

//     long long A,B;
//     int DA,DB;
//     int PA = 0,PB = 0;

//     int JA,JB;
//     int sa = 0, sb = 0;

//     scanf("%lld %d %lld %d",&A,&DA,&B,&DB);

//     //拿到A中DA的个数 
//     while( A != 0 ){

//         JA = A % 10;
//         if( JA == DA ){
//             PA = PA*10 + DA;
//         } 
//         A /= 10;
//     }

//     //拿到B中DB的个数 
//     while( B != 0 ){

//         JB = B % 10;
//         if(JB == DB){
//             PB = PB*10 + DB;
//         } 
//         B /= 10; 
//     }

//     printf("%d\n",PA+PB);

//     return 0;
// } 