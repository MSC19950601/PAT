#include <iostream> 

using namespace std;

int main() {
    int n;
    cin >> n;
    int jia_d = 0, yi_d = 0;
    while(n-- > 0){
        int a ,b ,c, d;
        cin >> a >> b >> c >> d;
        int true_res = a + c;
        if ((true_res == b && true_res == d) || (true_res != b && true_res != d)){
            jia_d += 0;
            yi_d += 0;
        }
        if ((true_res == b && true_res != d)){
            yi_d += 1;
        }
        if ((true_res != b && true_res == d)){
            jia_d += 1;
        }
    }
    cout << jia_d << " " << yi_d << endl;   
    return 0; 
}