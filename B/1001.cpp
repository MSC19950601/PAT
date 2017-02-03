 #include <iostream>

 int main() 
 {
     int n, step = 0;
     std::cin >> n ;
     while(n != 1){
         if(n%2 == 0)
         {
             n=n/2;
         }else
         {
             n=(3*n+1)/2;
         }
         step+=1;
     }
     std::cout << step;
     return 0;
 }