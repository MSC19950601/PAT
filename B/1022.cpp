 #include <iostream>

using namespace std;

 int main() 
 {
     int a, b, d;
     cin >> a;
     cin >> b;
     cin >> d;
     int sum = a + b;
     int z[31], num = 0;
     do{
        z[num++] = sum % d;
        sum = sum / d;
     }while(sum != 0);
     
     for(int i = num - 1; i >= 0; i--){
         cout << z[i];
     }
     return 0;
 } 